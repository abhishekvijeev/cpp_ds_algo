#include "include/vector.h"

#include <iostream>

int main() {

    practice::Vector<int> v{1,2,3};
    v.Push(10);
    v.Print();
    return 0;
}