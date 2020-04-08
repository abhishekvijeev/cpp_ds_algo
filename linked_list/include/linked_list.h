#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>
#include <iostream>

namespace practice {

    /*
     * Doubly linked list that tries to offer an RAII container interface
     * RAII (Resource Acquisition Is Initialization) - The technique of acquiring resources in
     * a constructor and releasing them in a destructor
     */

    template<typename T>
    class LinkedList {

    public:

        using value_type = T;

        LinkedList() : head{nullptr}, tail{nullptr}, size{0} {}

        /* 
         * Since we have explicitly specified a destructor, the move constructor and move
         * assignment operator will not be defined. However, default copy operations are
         * deprecated, and we must explicitly suppress these operations
         */

        // Suppressing copy construction
        LinkedList(const LinkedList&) = delete;

        // Suppressing copy assignment
        LinkedList& operator = (const LinkedList&) = delete;

        // Destructor
        ~LinkedList() { 
            // traverse list and free every node
        }

        /*
         * Simple operations must be inlined for efficiency (they are efficient because they are 
         * implemented without function calls in the generated machine code. Functions defined
         * inside classes are inlined by default)       
         */

        /*
         * const specifiers on functions indicate that these functions do not modify the object
         * for which they are called
         */

        // Operations
        unsigned long Size() const { return size; }

        bool IsEmpty() const { return Size() == 0; }

        value_type ValueAt(unsigned long index) const {
            
            if(index < 0 || index > Size())
                throw std::out_of_range("List index out of bounds!");

            ListNode* current = head.get();
            unsigned long curr_index = 0;
            value_type result;

            while(current != nullptr) {
                
                if(curr_index == index) {

                    result = current->data;
                    break;
                }
                current = (current->next).get();
            }

            return result;
        }

        void PushFront(value_type item) {

            std::shared_ptr<ListNode> tmp = std::make_shared<ListNode>(item);

            if(IsEmpty()) {
                
                /*
                 * tmp is 'moved' to head rather than 'copied' because tmp is a stack variable,
                 * and head can hence 'steal' tmp's pointer (as it will not be used again). Moving
                 * is much more efficient than copying, and is hence preferred in thsi case.
                 * However, we must increment the reference count for tail, and it is hence
                 * 'copied'.
                 */
                
                head = std::move(tmp);
                tail = head;
            }

            else {

                tmp->next = head;
                head->prev = tmp;
                head = tmp;
            }

            ++size;
        }

        value_type PopFront() {

            if(IsEmpty())
                throw std::underflow_error("List empty!");

            value_type data = head->data;
            head = head->next;
            --size;

            if(IsEmpty()) {

                head = nullptr;
                tail = nullptr;
            }
            else
                head->prev = nullptr;

            return data;

        }

        void PushBack(value_type item) {
            
            std::shared_ptr<ListNode> tmp = std::make_shared<ListNode>(item);

            if(IsEmpty()) {

                tail = std::move(tmp);
                head = tail;
            }
            else {

                tail->next = tmp;
                tmp->prev = tail;
                tail = tmp;
            }
            
            ++size;
        }

        value_type PopBack() {

            if(IsEmpty())
                throw std::underflow_error("List empty!");
            
            value_type data = tail->data;
            tail = tail->prev;
            --size;

            if(IsEmpty()) {

                head = nullptr;
                tail = nullptr;
            }
            else
                tail->next = nullptr;

            return data;
        }

        value_type Front() const { return head->data; }

        value_type Back() const { return tail->data; }

        void Insert(unsigned long index, value_type item) {
            
            if(index == 0)
                PushFront(item);

            else if(index == Size())
                PushBack(item);

            else {
                
                std::shared_ptr<ListNode> tmp = std::make_shared<ListNode>(item);
                std::shared_ptr<ListNode> current = head;
                unsigned long curr_index = 0;

                while(current != nullptr) {
                    
                    if(curr_index == index) {

                        std::shared_ptr<ListNode> prev_node = current->prev;
                        prev_node->next = tmp;
                        tmp->prev = prev_node;
                        tmp->next = current;
                        current->prev = tmp;

                        break;
                    }

                    ++curr_index;
                    current = current->next;
                }

                ++size;
            }

        }
        
        value_type Erase(unsigned long index) {
            
            if(index < 0 || index >= Size())
                throw std::out_of_range("List index out of bounds!");

            if(index == 0)
                return PopFront();
            
            else if(index == (Size() - 1))
                return PopBack();
            
            else {

                std::shared_ptr<ListNode> current = head;
                unsigned long curr_index = 0;
                value_type data;

                while(current != nullptr) {

                    if(curr_index == index) {

                        std::shared_ptr<ListNode> prev_node = current->prev;
                        std::shared_ptr<ListNode> next_node = current->next;
                        data = current->data;

                        prev_node->next = next_node;
                        current->prev = nullptr;
                        next_node->prev = prev_node;
                        current->next = nullptr;

                        break;
                    }

                    ++curr_index;
                    current = current->next;
                }


                --size;
                return data;
            }
            
        }

        void Traverse() const {
            
            ListNode* current = head.get();

            std::cout << "List contents:" << std::endl;

            while(current != nullptr) {

                std::cout << current->data << std::endl;
                current = (current->next).get();
            }
            std::cout << std::endl;
        }

        void TraverseReverse() const {
            
            ListNode* current = tail.get();

            std::cout << "List contents in reverse:" << std::endl;

            while(current != nullptr) {

                std::cout << current->data << std::endl;
                current = (current->prev).get();
            }
            std::cout << std::endl;
        }

    private:

        class ListNode {
        
            public:

            ListNode(value_type d) : data{d}, next{nullptr}, prev{nullptr} {}
            ~ListNode() {}

            value_type data;
            std::shared_ptr<ListNode> next;
            std::shared_ptr<ListNode> prev;

        };

        /*
         * Have to use shared_ptr over unique_ptr because nodes may be shared by the
         * head and tail pointers. Could do without the tail pointer (and change these
         * to unique_ptr), but that would imply a time-complexity increase for operations
         * PushBack(), PopBack() and Back(), which become O(n) with respect to the list's
         * size
         */
        
        std::shared_ptr<ListNode> head;
        std::shared_ptr<ListNode> tail;
        unsigned long size;
        
    };
}

#endif