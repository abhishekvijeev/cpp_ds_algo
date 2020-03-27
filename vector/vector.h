#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <algorithm>    

namespace practice {

    class Vector {

    public:

        //Constructors
        Vector() {}
        Vector(int capacity) : ar{new int[capacity]}, capacity{capacity}, size{0} {}
        //allows initializing the vector via a user-defined initializer list
        Vector(const std::initializer_list<int> &); 

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

        //Copy Constructor
        Vector(const Vector&);

        // Move Constructor
        Vector(Vector&&); 

        // Assignment Operator
        // - If the argument passed is an lvalue, it is copy constructed
        // - If the argument is an rvalue, it is move constructed
        Vector& operator = (Vector);

        //Destructor
        ~Vector() {}

        // Operations
        int Size();
        int Capacity();
        bool IsEmpty();
        int At(int index);
        void Push(int item);
        void Insert(int item, int index);
        void Prepend(int item);
        int Delete(int index);
        int Pop();
        void Remove(int item);
        int Find(int item);
        void Print();

    private:    

        int *ar;
        int capacity;
        int size;

        static constexpr int kGrowthFactor = 2;
        static constexpr int kShrinkFactor = 4;
        static constexpr int kMinCapacity = 1;

        void Expand();
        void Shrink();

    };

}

#endif