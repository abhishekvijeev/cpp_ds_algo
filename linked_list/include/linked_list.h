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

        LinkedList() : head{nullptr}, tail{nullptr} {}

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
        unsigned long Size() const {

            ListNode* current = head.get();
            unsigned long size = 0;

            while(current != nullptr) {

                ++size;
                current = (current->next).get();
            }

            return size;
        }

        bool IsEmpty() const;

        value_type ValueAt(unsigned long index) const;

        void PushFront(value_type item) {

            std::shared_ptr<ListNode> tmp = std::make_shared<ListNode>(item);

            if(head == nullptr) {
                
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

        }

        value_type PopFront();

        void PushBack(value_type item);

        value_type PopBack();

        value_type Front() const { return head->data; }

        value_type Back() const { return tail->data; }

        void Insert(unsigned long index, value_type item);
        
        value_type Erase(unsigned long index);

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
        
    };
}

#endif