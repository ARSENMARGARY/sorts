#include <iostream>

template<typename T>
void swap(T& lhs,T& rhs)
{
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}