#include <iostream>
#include <algorithm>
#include <set>
#include <list>

// std::max_element(it_begin, it_end, comparator);          //returns iterator, comparator (comparison function object) is optional
// comparator: bool comp(const Type1 &a, const Type2 &b);   //returns ​true if a is less than b.

int main(){

    //std::vector<int> v {3,400,51,6,7,23,56,71};
    //int v[] {3,400,51,6,7,1123,56,71};
    std::list<int> v {3,400,51,6,7,23,56,71};

    //max_elt and min_elt return an iterator to the found elt
    auto result = std::max_element(std::begin(v), std::end(v));
    std::cout << "max element is : " << *result << std::endl;
    
    result = std::min_element(std::begin(v),std::end(v));
    std::cout << "min element is : " << *result << std::endl;


    std::cout << "----------" << std::endl;

    //Distances : closest and furthest
    int number_to_find {100};
    
    //custom comparator: find the number that's closet to "number_to_find"
    auto distance = [number_to_find](int x, int y){
        return (std::abs(x-number_to_find) < std::abs(y-number_to_find));
    };
    
    //Finding the closest, returns iterator
    result = std::min_element(std::begin(v),std::end(v),distance);
    std::cout << *result << " is closest to " << number_to_find << std::endl;
    
    //Finding the furthest
    result = std::max_element(std::begin(v),std::end(v),distance);
    std::cout << *result << " is furthest from  " << number_to_find << std::endl;


    std::cout << "--------------------------------" << std::endl;

    //Capturing min and max in a pair object with the auto syntax
    const auto[near,far] = std::minmax_element(std::begin(v),std::end(v),distance);
    std::cout << *near << " is closest to " << number_to_find << std::endl;
    std::cout << *far << " is furthest from  " << number_to_find << std::endl;
    
    return 0;
}