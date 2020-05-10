#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <initializer_list>
#include <algorithm>
#include <iostream>

namespace practice {

    /*
     * Template types MUST overload the following relational operators to work:
     * <, <=, >, >=, ==, !=
     * The reason is that Heapify() comapares elemts using these relational operators
     */
    template<typename T>
    class Heap {

    public:

        using value_type = T;

        Heap() {}

        Heap(const std::initializer_list<value_type>& list) { 

            array.resize(list.size());
            std::copy(list.begin(), list.end(), array.begin());
            PrintArray();
        }

        // Operations

        void Heapify() { Heapify(0); }

        void BuildHeap() {

            size_t size = array.size();
            for(int i = (size / 2) - 1; i >= 0; --i) {
                std::cout << "Heapify(" << i << ")" << std::endl;
                Heapify(i);
            }

        }

        //  REMOVE THIS
        void PrintArray() {
            for(size_t i = 0; i < array.size(); ++i)
                std::cout << array[i] << std::endl;
        }

    private:

        std::vector<value_type> array;

        

        void Heapify(size_t node_index) {
            
            // std::cout << "Heapify(" << node_index << ")" << std::endl;
            size_t largest_index = node_index;
            value_type left_child_index = (node_index * 2) + 1;
            value_type right_child_index = (node_index * 2) + 2;

            std::cout << "node_index:" << node_index << std::endl;
            std::cout << "left_child_index: " << left_child_index << std::endl;
            std::cout << "right_child_index: " << right_child_index << std::endl;
            
            if(left_child_index >= 0 && left_child_index < array.size() && array[node_index] < array[left_child_index]) {
                largest_index = left_child_index;
            }
            if(right_child_index >= 0 && right_child_index < array.size() && array[largest_index] < array[right_child_index]) {
                largest_index = right_child_index;
            }
            std::cout << "largest_index: " << largest_index << std::endl;
            if(largest_index != node_index) {

                std::swap(array[node_index], array[largest_index]);
                // int tmp = array[node_index];
                // array[node_index] = array[largest_index];
                // array[largest_index] = tmp;
                Heapify(largest_index);
            }

        }
        
    };

}

#endif