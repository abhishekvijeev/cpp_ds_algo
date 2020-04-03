#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace practice {

    /*
     * Doubly linked list that tries to offer an RAII container interface
     * RAII (Resource Acquisition Is Initialization) - The technique of acquiring resources in
     * a constructor and releasing them in a destructor
     */

    class LinkedList {

    public:

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

        void PushFront(int);

        /*
         * Simple operations must be inlined for efficiency (they are efficient because they are 
         * implemented without function calls in the generated machine code. Functions defined
         * inside classes are inlined by default)       
         */

        /*
         * const specifiers on functions indicate that these functions do not modify the object
         * for which they are called
         */
        int front() const {return head->data;};

    private:

        class ListNode {
        
            public:

            ListNode() : data{0} {}
            ListNode(int d) : data{d} {}
            ~ListNode() {}

            int data;
        };

        ListNode *head;
        ListNode *tail;
        

    };
}

#endif