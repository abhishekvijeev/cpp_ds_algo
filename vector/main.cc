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
    cout << endl;

    // Testing copy constructor
    practice::Vector<int> v2;
    cout << "Created new vector using the copy constructor" << endl;
    v2 = v;
    v2.Print();
    cout << "Size: " << v2.Size() << ", capacity: " << v2.Capacity() << endl;
    cout << endl;

    // Testing move constructor
    practice::Vector<int> v3;
    v3 = static_cast<practice::Vector<int>&&>(practice::Vector<int> {1,2});
    cout << "Created new vector using the move constructor" << endl;
    v3.Print();
    cout << "Size: " << v3.Size() << ", capacity: " << v3.Capacity() << endl;
    return 0;
}