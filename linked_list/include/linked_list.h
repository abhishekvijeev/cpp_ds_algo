#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>

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
        unsigned long Size() const;

        bool IsEmpty() const;

        value_type ValueAt(unsigned long index) const;

        void PushFront(value_type item);

        value_type PopFront();

        void PushBack(value_type item);

        value_type PopBack();

        value_type Front() const;

        value_type Back() const;

        void Insert(unsigned long index, value_type item);
        
        value_type Erase(unsigned long index);

    private:

        class ListNode {
        
            public:

            ListNode() {}
            ListNode(value_type d) : data{d} {}
            ~ListNode() {}

            value_type data;
        };

        std::unique_ptr<ListNode> head;
        std::unique_ptr<ListNode> tail;
        
    };
}

#endif