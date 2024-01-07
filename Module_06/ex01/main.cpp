#include "iostream"

#include "Data.hpp"
#include <iostream>

int main()
{
    Data *ds = new Data;
    ds->a = 42;
    ds->b = 21;

    std::cout << ds << std::endl;
    uintptr_t rawPtr = Serializer::serialize(ds);
    std::cout << rawPtr << std::endl;

    float* ptr = reinterpret_cast<float*>(rawPtr);
    std::cout << *ptr << std::endl;
    ptr++;
    std::cout << *ptr << std::endl;

    Data *tmp = NULL;
    tmp = Serializer::deserialize(rawPtr);
    std::cout << tmp << std::endl;
    std::cout << tmp->a << std::endl << tmp->b << std::endl;
    delete ds;
    return 0;
}
