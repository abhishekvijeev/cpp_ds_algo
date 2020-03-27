#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <algorithm>    

namespace practice {
    
    template <typename T>
    class Vector {

    public:

        using value_type = T;
        //Constructors
        Vector() : ar{nullptr}, capacity{0}, size{0} {}
        Vector(int capacity) : ar{new value_type[capacity]}, capacity{capacity}, size{0} {}
        //allows initializing the vector via a user-defined initializer list
        

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
        value_type At(int index);
        void Push(value_type item);
        void Insert(value_type item, int index);
        void Prepend(value_type item);
        value_type Delete(int index);
        value_type Pop();
        void Remove(value_type item);
        int Find(value_type item);
        void Print();

        // To support a ranged for loop, we must define begin() and end() functions
        value_type* begin() {return &ar[0];}
        value_type* end() {return begin() + size;}

    private:    

        value_type *ar;
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