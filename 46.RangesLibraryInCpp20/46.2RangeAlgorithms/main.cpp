#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>
#include <concepts>

//range algorithms operate without user specified iterator pair and work with containers directly.
//lives in std::ranges namespace

template<typename T>
void print_collection( const T& collection){
    
    std::cout << " Collection [" ;
    for(const auto& elt : collection){
        std::cout << " " << elt ;
    }
    std::cout << "]" << std::endl;
}


int main(){

	std::vector<int> numbers {11,2,6,4,8,3,17,9};
    print_collection(numbers);

    //std::ranges::all_of()
    std::cout << std::endl;
    std::cout << "std::ranges::all_of() : " << std::endl;
    auto odd = [](int n){
        return n%2 !=0;
    };
    auto result = std::ranges::all_of(numbers,odd);

    if(result){
        std::cout << "All elements in numbers are odd" << std::endl;
    }else{
        std::cout << "Not all elements in numbers are odd" << std::endl;
    }



    //For each
    std::cout << std::endl;
    std::cout << "std::ranges::for_each() : " << std::endl;
    print_collection(numbers);
    std::ranges::for_each(numbers,[](int& n){n*=2;});
    print_collection(numbers);


    //Sort
    std::cout << std::endl;
    std::cout << "std::ranges::sort() : " << std::endl;
    print_collection(numbers);
    std::ranges::sort(numbers);
    print_collection(numbers);


    //Find
    std::cout << std::endl;
    std::cout << "std::ranges::find() : " << std::endl;
    auto odd_n_position = std::ranges::find_if(numbers,odd);
    
    if (odd_n_position != std::end(numbers)) {
        std::cout << "numbers contains at least one odd number : " << *odd_n_position  << std::endl;
    } else {
        std::cout << "numbers does not contain any odd number" << std::endl;
    }


    //Important, copying into outputstream on the fly
    std::cout << std::endl;
    std::cout << "std::ranges::copy()\n";
    std::cout << "numbers : " ;
    std::ranges::copy(numbers,std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

   /*Ostream iterators are output iterators that write sequentially to an output stream (such as cout).
    
    They are constructed from a basic_ostream object, to which they become associated, so that whenever an assignment operator (=) is used on the ostream_iterator (de-referenced or not) it inserts a new element into the stream.

    Optionally, a delimiter can be specified on construction. This delimiter is written to the stream after each element is inserted.
    */
    return 0;
}