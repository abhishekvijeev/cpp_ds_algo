#include "linked_list.h"

namespace practice {

    void LinkedList::PushFront(int value) {
        head = new ListNode(value);
    }

}