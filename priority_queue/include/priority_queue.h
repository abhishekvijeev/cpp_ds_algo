#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <limits>

namespace practice {
    
    /*
     * A priority queue implementation using max heaps for integers only. An application specific
     * PriorityQueue implementation would need to determine which application object corresponds
     * to a given PriorityQueue element and vice-versa. Each element of the PriorityQueue would
     * therefore need to store a handle (usually in the form of a pointer) to the corresponding
     * application object. Similarly, we will need to store a handle to the corresponding 
     * PriorityQueue element (usually an array index) in each application object. We ignore
     * such details for now and only focus on implementing a PriorityQueue for integers, where
     * the integer's value determines its position in the PriorityQueue
     */
    class PriorityQueue {

    public:

        PriorityQueue() {}

        PriorityQueue(const std::initializer_list<int>& list) { 

            pqueue.resize(list.size());
            std::copy(list.begin(), list.end(), pqueue.begin());
            BuildMaxHeap();
            PrintPriorityQueue();
        }

        PriorityQueue(const std::vector<int>& vec) { 

            pqueue.resize(vec.size());
            std::copy(vec.begin(), vec.end(), pqueue.begin());
            BuildMaxHeap();
            PrintPriorityQueue();
        }

        // Operations

        bool IsEmpty() {
            return pqueue.size() == 0;
        }
        
        int GetMax() {

            if(IsEmpty())
                throw std::underflow_error("Priority Queue is empty!");

            return pqueue[0];
        }

        int ExtractMax() {

            if(IsEmpty())
                throw std::underflow_error("Priority Queue is empty!");

            int max = GetMax();
            std::swap(pqueue[0], pqueue[pqueue.size() - 1]);
            pqueue.pop_back();
            SiftDown(0);
            return max;
        }

        void IncreaseKey(size_t index, int new_key) {

            if(IsEmpty())
                throw std::underflow_error("Priority Queue is empty!");
            
            if(index < 0 || index >= pqueue.size())
                throw std::out_of_range("Priority Queue index out of bounds!");
            
            if(new_key <= pqueue[index])
                throw std::invalid_argument("New key must be greater than existing key!");
            
            pqueue[index] = new_key;
            SiftUp(index);
        }
        
        

        void Insert(int data) {
            
            pqueue.push_back(std::numeric_limits<int>::min());
            IncreaseKey(pqueue.size() - 1, data);
            std::cout << "IsMaxHeap(): " << IsMaxHeap() << std::endl;
        }

        int Remove(size_t index) {

            if(IsEmpty())
                throw std::underflow_error("Priority Queue is empty!");
            
            if(index < 0 || index >= pqueue.size())
                throw std::out_of_range("Priority Queue index out of bounds!");

            std::swap(pqueue[index], pqueue[pqueue.size() - 1]);
            pqueue.pop_back();
            SiftDown(index);
        }

        void PrintPriorityQueue() {
            for(size_t i = 0; i < pqueue.size(); ++i)
                std::cout << pqueue[i] << std::endl;
        }
        
    private:

        void SiftUp(size_t index) {

            while(index > 0 && pqueue[index] > pqueue[Parent(index)]) {
                std::swap(pqueue[index], pqueue[Parent(index)]);
                index = Parent(index);
            }

        }

        void SiftDown(size_t index) {

            size_t largest_index = index;
            size_t left_child_index = LeftChild(index);
            size_t right_child_index = RightChild(index);
            
            if(left_child_index >= 0 && left_child_index < pqueue.size() && 
                pqueue[index] < pqueue[left_child_index]) {

                largest_index = left_child_index;
            }

            if(right_child_index >= 0 && right_child_index < pqueue.size() &&
                pqueue[largest_index] < pqueue[right_child_index]) {

                largest_index = right_child_index;
            }

            if(largest_index != index) {

                std::swap(pqueue[index], pqueue[largest_index]);
                SiftDown(largest_index);
            }

        }

        size_t Parent(size_t index) {

            return (index - 1) / 2;
        }       

        size_t LeftChild(size_t index) {

            return (index * 2) + 1;
        } 

        size_t RightChild(size_t index) {

            return (index * 2) + 2;
        }

        void BuildMaxHeap() {
            
            for(int i = (pqueue.size() / 2) - 1; i >= 0; --i)
                SiftDown(i);
            
            std::cout << "IsMaxHeap(): " << IsMaxHeap() << std::endl;
        }

        bool IsMaxHeap() {
            for(int node_index = 0; node_index < pqueue.size(); ++node_index) {
                size_t left_child_index = LeftChild(node_index);
                size_t right_child_index = RightChild(node_index);

                if(left_child_index >= 0 && left_child_index < pqueue.size() &&
                    pqueue[node_index] < pqueue[left_child_index])
                    return false;

                if(right_child_index >= 0 && right_child_index < pqueue.size() &&
                    pqueue[node_index] < pqueue[right_child_index])
                    return false;
            }
            return true;
        }
        
        std::vector<int> pqueue;
    };

}

namespace heapsort {

    size_t Parent(size_t index) {

        return (index - 1) / 2;
    }       

    size_t LeftChild(size_t index) {

        return (index * 2) + 1;
    } 

    size_t RightChild(size_t index) {

        return (index * 2) + 2;
    }

    void SiftDown(std::vector<int>& arr, size_t index, int arr_size) {
            
        size_t largest_index = index;
        size_t left_child_index = LeftChild(index);
        size_t right_child_index = RightChild(index);
        
        if(left_child_index >= 0 && left_child_index < arr_size && 
            arr[index] < arr[left_child_index]) {

            largest_index = left_child_index;
        }

        if(right_child_index >= 0 && right_child_index < arr_size &&
            arr[largest_index] < arr[right_child_index]) {

            largest_index = right_child_index;
        }

        if(largest_index != index) {

            std::swap(arr[index], arr[largest_index]);
            SiftDown(arr, largest_index, arr_size);
        }

    }

    void BuildMaxHeap(std::vector<int>& arr) {
            
        for(int i = (arr.size() / 2) - 1; i >= 0; --i) {
            SiftDown(arr, i, arr.size());
        }
    }

    void HeapSort(std::vector<int>& arr) {
        
        BuildMaxHeap(arr);
        int size = arr.size();
        for(int i = arr.size() - 1; i > 0; --i) {
            std::swap(arr[i], arr[0]);
            --size;
            SiftDown(arr, 0, size);
        }
    }
}

#endif