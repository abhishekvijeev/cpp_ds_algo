#include "heap.h"

#include <iostream>

using namespace std;

int main() {

    practice::Heap<int> h {4,1,3,2,16,9,10,14,8,7};
    h.BuildHeap();
    h.PrintArray();
    return 0;

}