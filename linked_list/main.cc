#include "linked_list.h"

#include <iostream>

using namespace std;

int main() {

    practice::LinkedList<int> my_list;
    my_list.PushFront(10);
    my_list.PushFront(20);
    my_list.PushFront(30);
    cout << "Size: " << my_list.Size() << endl;
    // cout << my_list.Front() << " " << my_list.Back() << endl;
    
}