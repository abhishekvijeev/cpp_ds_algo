#include "priority_queue.h"

#include <iostream>

using namespace std;

int main() {

    practice::PriorityQueue pq {4,1,3,2,16,9,10,14,8,7};
    cout << endl;
    pq.Insert(15);
    pq.PrintPriorityQueue();
    
    vector<int> x{5,7,29,12,34,2,15};
    heapsort::HeapSort(x);
    for(int i : x) 
        cout << i << ",";
    cout << endl;
    return 0;

}