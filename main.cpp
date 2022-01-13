#include "utility.h"
#include <vector>
#include <iostream>


template<typename T>
void selection_sort(std::vector<T>& array)
{
    typedef typename std::vector<T>::iterator Itr;
    Itr itr = array.begin();
    while(itr != array.end())
    {
        Itr itr_min = itr;
        for(Itr i = itr + 1; i != array.end(); i++)
        {
            if(*i < *itr_min)
            {
                itr_min = i;
            }
        }
        swap(*itr, *itr_min);
        itr++;
    }
}

template<typename T>
void bubble_sort(std::vector<T>& array)
{
    typename std::vector<T>::iterator Itr = array.begin();
    bool changed;

    for(; Itr != array.end(); ++Itr)
    {
            changed = false;
            auto i = std::next(Itr, 1);

         for(; i != array.end(); ++i)
        {
            if(*i < *Itr)
            {
                std::swap(*i,*Itr);
                changed = true;
            }
            
        }
        if(!changed)
        {
            break;
        }
    }

}

template<typename T>
void insertion_sort(std::vector<T> &array) {
    for (auto it = array.begin() + 1; it != array.end(); ++it)
    {
        auto key = it;

        for (auto i = it - 1; i >= array.begin(); --i)
        {
            if (*i > *key) {
                swap(*i, *key);
                key--;
            } else {
                break;
            }
        }
    }
}

template<typename T>
T binary_search(std::vector<T>& array,T start, T end, T key)
{
if(start <= end){
    auto mid = (start + end) / 2;
    if(array[mid] == key)
    {
        return mid;
    }
    if(array[mid] > key)
    {
        return binary_search(array,start,mid - 1,key);
    }
     if(array[mid] < key)
    {
        return binary_search(array,mid + 1,end,key);
    }
}
    return -1;
}



template<typename T>
void print(const std::vector<T>& array)
{
    for(auto itr = array.begin(); itr != array.end(); itr++)
    {
       std::cout << *itr << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> v({5, 3, 12, 2, 8});
    std::cout << "Original Array :";
    print(v);
   // selection_sort(v);
   // bubble_sort(v);
    insertion_sort(v);
    std::cout <<"Sorted Array :";
    print(v);
    std::cout << '\n';


}


