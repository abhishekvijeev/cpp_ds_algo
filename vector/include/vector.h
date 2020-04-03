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

        // Operations

        /*
         ***********************
         * THROW EXCEPTIONS!!! 
         ***********************
         */

        unsigned long Size();
        unsigned long Capacity();
        bool IsEmpty();
        value_type At(int index);   //throw out_of_range exception

        void Push(value_type item) {

            array[size] = item;
            ++size;
        }

        void Insert(value_type item, int index);
        void Prepend(value_type item);
        value_type Delete(int index);
        value_type Pop();
        void Remove(value_type item);
        int Find(value_type item);

        void Print() {

            for(unsigned long i = 0; i < size; ++i)
                std::cout << array[i] << " ";
            std::cout << std::endl;
        }

        // To support a ranged for loop, we must define begin() and end() functions
        value_type* begin() {return &array[0];}
        value_type* end() {return begin() + size;}

        // Overload subscript operators
        value_type& operator[](int i) const {return At(i);}

    private:    

        value_type *array;
        unsigned long capacity;
        unsigned long size;

        static constexpr int kGrowthFactor = 2;
        static constexpr int kShrinkFactor = 4;
        static constexpr int kMinCapacity = 1;

        void Expand();
        void Shrink();

    };

}

#endif