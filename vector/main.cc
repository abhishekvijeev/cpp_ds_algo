#include "include/vector.h"

#include <iostream>

using namespace std;

int main() {

    practice::Vector<int> v(1);

    v.Push(10);
    v.Push(20);
    v.Push(30);
    v.Push(40);
    v.Push(50);

    v.Print();
    cout << "Size: " << v.Size() << ", capacity: " << v.Capacity() << endl;

    v.Insert(100, 0);
    v.Insert(200, 6);
    v.Prepend(300);

    v.Print();
    cout << "Size: " << v.Size() << ", capacity: " << v.Capacity() << endl;

    v.Pop();
    v.Delete(1);
    v.Delete(0);
    
    v.Print();
    cout << "Size: " << v.Size() << ", capacity: " << v.Capacity() << endl;

    v.Push(60);
    v.Push(60);
    v.Push(70);

    v.Print();
    cout << "Size: " << v.Size() << ", capacity: " << v.Capacity() << endl;

    v.Remove(60);

    v.Print();
    cout << "Size: " << v.Size() << ", capacity: " << v.Capacity() << endl;

    int elem = 70;
    int index = v.Find(elem);
    cout << "Index of " << elem << " = " << index << endl;

    v[5] = 100;
    v[1] = 200;
    v.Print();
    cout << "Size: " << v.Size() << ", capacity: " << v.Capacity() << endl;
    return 0;
}