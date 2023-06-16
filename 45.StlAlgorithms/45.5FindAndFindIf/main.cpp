#include <iostream>
#include <algorithm>
#include <vector>

// find things in collections
// std::find(it_begin, it_end, n);      //find n, if found return an iterator to the first element in the range, if not return iterator pointing to the past-the-end
// std::find_if(it_begin, it_end, predicate);      //if predicate is true, return an iterator to the first element in the range that satisfies the predicate, if false return iterator pointing to the past-the-end

int main(){

    //int n = 23;
    int n = 24;
 
    std::vector<int> collection{14, 24,72, 8, 98, 112};

    //returns iterator rathan than value
    auto result = std::find(std::begin(collection), std::end(collection), n);
 
    if (result != std::end(collection)) {
        std::cout << "collection contains: " << *result << std::endl;
    } else {
        std::cout << "collection does not contain: " << n << std::endl;
    }

    std::cout << "------------" << std::endl;

    //find_if
    //prdicate
    auto odd = [](int x){
        if( (x%2) != 0)
            return true;
        return false;
    };
    
    auto odd_n_position = std::find_if(std::begin(collection),std::end(collection),odd);
    
    if (odd_n_position != std::end(collection)) {
        std::cout << "collection contains at least one odd number : " << *odd_n_position  << std::endl;
    } else {
        std::cout << "collection does not contain any odd number" << std::endl;
    }
    
    return 0;
}