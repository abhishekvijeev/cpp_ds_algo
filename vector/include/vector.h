#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <algorithm>    
#include <memory>
#include <iostream>

namespace practice {
    
    template <typename T>
    class Vector {

    public:

        // Template alias
        using value_type = T;

        /*
         * Rule of Five: 
         * 
         * "For a class that manages a resource, If you need to explicitly declare either the 
         * destructor, copy constructor, copy assignment operator, move constructor or move
         * assignment operator yourself, you probably need to explicitly declare all five of them."
         * 
         * References:
         * [1] https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three
         * [2] https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
         * [3] https://stackoverflow.com/questions/3106110/what-is-move-semantics
         * 
         */

        // Default and parameterized constructors
        Vector() : 
            array{nullptr},
            capacity{0},
            size{0} {
        }

        Vector(unsigned long capacity) : 
            array{new value_type[capacity]},
            capacity{capacity},
            size{0} {
        }

        Vector(std::initializer_list<value_type> list) : 
            array{new value_type[list.size()]},
            capacity{list.size()},
            size{list.size()} {

            std::copy(list.begin(), list.end(), array);
            
        }

        //Copy Constructor
        Vector(const Vector&);

        // Move Constructor
        Vector(Vector&&); 

        // Assignment Operator
        // - If the argument passed is an lvalue, it is copy constructed
        // - If the argument is an rvalue, it is move constructed
        Vector& operator = (Vector);

        //Destructor
        ~Vector() {

            if(array != nullptr) 
                delete[] array;
        }

        // Vector Operations

        unsigned long Size() const { return size; }

        unsigned long Capacity() const {return capacity; }

        bool IsEmpty() const {return size == 0; }

        value_type At (int index) const{

            if(index < 0 || index >= size)
                throw std::out_of_range("Array index out of bounds!");
            
            return array[index];

        }  

        void Push(value_type item) {
            
            if(size == capacity)
                Expand();

            array[size] = item;
            ++size;
        }

        void Insert(value_type item, int index) {

            if(index < 0 || index > size)
                throw std::out_of_range("Array index out of bounds!");
            
            if(size == capacity)
                Expand();

            for(int i = size; i > index; --i)
                array[i] = array[i - 1];

            array[index] = item;
            ++size;
        }

        void Prepend(value_type item) { Insert(item, 0); }

        value_type Delete(int index) {

            if(index < 0 || index >= size)
                throw std::out_of_range("Array index out of bounds!");

            int data = array[index];

            for(int i = index; i < size; ++i) 
                array[i] = array[i + 1];
            
            --size;
            if(size * kShrinkFactor < capacity)
                Shrink();
            
            return data;
        }

        value_type Pop() { return Delete(size - 1); }

        // Could be improved to indicate that the element was not found
        void Remove(value_type item) {

            for(int i = 0; i < size; ++i) {

                if(array[i] == item) {

                    Delete(i);
                    --i;
                }
            }

        }

        int Find(value_type item) {

            for(int i = 0; i < size; ++i) {

                if(array[i] == item)
                    return i;
            }

            return -1;

        }

        void Print() {

            for(unsigned long i = 0; i < size; ++i)
                std::cout << array[i] << " ";

            std::cout << std::endl;
        }

        // To support a ranged for loop, we must define begin() and end() functions
        value_type* begin() {return &array[0];}
        value_type* end() {return begin() + size;}

        // Overload subscript operators
        value_type& operator[](int index) const {

            if(index < 0 || index >= size)
                throw std::out_of_range("Array index out of bounds!");
            
            return array[index];

        }

    private:    

        value_type* array;
        unsigned long capacity;
        unsigned long size;

        static constexpr int kGrowthFactor = 2;
        static constexpr int kShrinkFactor = 4;
        static constexpr int kMinCapacity = 1;

        void Expand() {

            capacity = capacity * kGrowthFactor;
            value_type* old_array = array;

            array = new value_type[capacity];
            
            for(int i = 0; i < size; ++i) 
                array[i] = old_array[i];
            

            delete[] old_array;
        }

        void Shrink() {

            value_type* old_array = array;
            capacity = capacity / kShrinkFactor;
            array = new value_type[capacity];

            for(int i = 0; i < size; ++i)
                array[i] = old_array[i];
            
            delete[] old_array;
        }

    };

}

#endif