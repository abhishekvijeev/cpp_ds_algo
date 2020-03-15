#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <algorithm>    

namespace practice {

    class Vector {

    public:

        Vector(int capacity) : ar{new int[capacity]}, capacity(capacity), size(0) {}
        //allows initializing the vector via a user-defined initializer list
        Vector(const std::initializer_list<int> &); 

    private:

        int *ar;
        int capacity;
        int size;

    };

}

#endif