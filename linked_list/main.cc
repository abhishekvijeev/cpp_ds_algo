#include "linked_list.h"

#include <iostream>

using namespace std;

int main() {

    practice::LinkedList<int> my_list;
    my_list.PushFront(10);
    my_list.PushFront(20);
    my_list.PushFront(30);
    cout << "Size: " << my_list.Size() << endl;
    my_list.Traverse();
    my_list.TraverseReverse();

    cout << "PopFront(): " << my_list.PopFront() << std::endl;
    cout << "Size: " << my_list.Size() << endl;
    my_list.Traverse();
    my_list.TraverseReverse();

    my_list.PushBack(40);
    my_list.PushBack(50);
    cout << "Size: " << my_list.Size() << endl;
    my_list.Traverse();
    my_list.TraverseReverse();

    cout << "PopBack(): " << my_list.PopBack() << std::endl;
    cout << "Size: " << my_list.Size() << endl;
    my_list.Traverse();
    my_list.TraverseReverse();

    my_list.Insert(0, 100);
    cout << "Size: " << my_list.Size() << endl;
    my_list.Traverse();
    my_list.TraverseReverse();

    my_list.Insert(my_list.Size(), 200);
    cout << "Size: " << my_list.Size() << endl;
    my_list.Traverse();
    my_list.TraverseReverse();

    my_list.Insert(3, 300);
    cout << "Size: " << my_list.Size() << endl;
    my_list.Traverse();
    my_list.TraverseReverse();
    // cout << my_list.Front() << " " << my_list.Back() << endl;

    cout << "Erase(1): " << my_list.Erase(1) << std::endl;
    cout << "Erase(1): " << my_list.Erase(1) << std::endl;
    cout << "Erase(1): " << my_list.Erase(1) << std::endl;
    cout << "Erase(1): " << my_list.Erase(1) << std::endl;
    cout << "Erase(1): " << my_list.Erase(1) << std::endl;
    cout << "Erase(0): " << my_list.Erase(0) << std::endl;
    cout << "Size: " << my_list.Size() << endl;
    my_list.Traverse();
    my_list.TraverseReverse();
    
}