#include "vector.h"

namespace practice {

    Vector::Vector(const std::initializer_list<int> &list) :
        Vector(list.size()) {

        //initialize vector using initializer list
        std::copy(list.begin(), list.end(), ar);
    }
}