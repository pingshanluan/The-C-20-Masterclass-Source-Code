#include <iostream>
#include <algorithm>
#include <vector>

// to copy data from one collection to the other
// std::copy(source_it_first, source_it_last, dest_it_first);    //copy elements in [source_it_first, source_int_last) to dest starting from it_first

// std::copy_if(source_it_first, source_it_last, dest_it_first, pred);      //copy based on predicates. Only copies the elements in source  which the predicate pred returns true. The relative order of the elements that are copied is preserved. The behavior is undefined if the source and the dest ranges overlap, surplus elements will just be ignored.

template<typename T>
void print_collection( const T& collection){
    std::cout << " Collection [" ;
    for(const auto& elt : collection){
        std::cout << " " << elt ;
    }
    std::cout << "]" << std::endl;
}

int main(){

    //std::vector<int> source {1,2,3,4,5,6,7,8,9};
    int source[] {1,2,3,4,5,6,7,8,9};   

    std::vector<int> dest {15,21,12,53,30,40};
    
    std::cout << "source : ";
    print_collection(source);
    
    std::cout << "dest : ";
    print_collection(dest);
    
    //Copy from source to dest
    //Copy elements from source in the range [std::begin(source),std::begin(source) + 4 ) 
    //to dest, starging from iterator std::begin(dest)
    //Make sure you are copying from valid ranges either in dest or source.
    std::copy(std::begin(source),std::begin(source) + 4,std::begin(dest));
    
    std::cout << "source(after copy) : ";
    print_collection(source);
    
    std::cout << "dest(after copy) : ";
    print_collection(dest);

    std::cout << "---------------------------" << std::endl;
 
    std::vector<int> dest1{100,200,300,400,500,600};
    
    std::cout << "source : ";
    print_collection(source);
    
    std::cout << "dest1 : " ;
    print_collection(dest1);
    
    auto odd = [](int n){
        return ((n%2)!=0);
    };

    
    //If there are more elements in source than the space available in dest,
    //surplus elements will just be ignored.
    std::copy_if(std::begin(source),std::end(source),std::begin(dest1),odd);
    
    std::cout << "source(after copy) : ";
    print_collection(source);
    
    std::cout << "dest1(after copy) : " ;
    print_collection(dest1);
   
    return 0;
}