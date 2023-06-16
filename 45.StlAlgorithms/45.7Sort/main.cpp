#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

// for sort to work, the container must have random access iterator (RandomIT). This means it work on list, deque, set, map, etc.
// std::sort(source_it_first,source_it_last);   //sorting source elements from it_first to it_last
// possible to specify a predicate. as all other algorithms, std::less() is used by default.

class Book{
    friend std::ostream& operator<< (std::ostream& out, const Book& operand);
public : 

    Book(int year, std::string title) 
        : m_year(year),m_title(title)
        {
        }
    //overloading < to be used in sort predicate
    bool operator< (const Book & right_operand)const{
        return this->m_year < right_operand.m_year;
    }
    
    //overloading > to be used in sort predicate
    bool operator> (const Book & right_operand)const{
        return this->m_year > right_operand.m_year;
    }
   
      
    bool operator==(const Book&  right_operand)const{
        return (this->m_year == right_operand.m_year);
    }
   
    
public : 
    int m_year;
    std::string m_title;
};

//overloading stream operator for out stream
std::ostream& operator<< (std::ostream& out, const Book& operand){
    out << "Book [" << operand.m_year << ", " << operand.m_title << "]";
    return out;
}



template<typename T>
void print_collection( const T& collection){
    
    std::cout << " Collection [" ;
    //print out each element
    for(const auto& elt : collection){
        std::cout << " " << elt ;
    }
    std::cout << "]" << std::endl;
}



int main(){
    
    //Directly without predicate
    std::vector<int> collection = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
    
    std::cout << "collection(unsorted) : ";
    print_collection(collection);
    
    std::sort(std::begin(collection),std::end(collection));
    
    std::cout << "collection(sorted) : ";
    print_collection(collection);
    
    
    std::cout << "---------------------------" << std::endl;


    //With custom predicate (compare function)
    collection = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
    
    std::cout << "collection(unsorted) : ";
    print_collection(collection);
    
    //std::sort(std::begin(collection),std::end(collection),std::less<int>());
    //std::sort(std::begin(collection),std::end(collection),std::greater<int>());

    //lambda as pred
    std::sort(std::begin(collection),std::end(collection),[](int x, int y){return x < y;});
    
    std::cout << "collection(sorted) : ";
    print_collection(collection);
    
    
    std::cout << "--------------------------" << std::endl;

    //Sorting collections of custom items
    std::vector<Book> books {Book(1734,"Cooking Food"),
                    Book(2000,"Building Computers"),Book(1995,"Farming for Beginners")};
                    
                    
    std::cout << "books(before sort) : " << std::endl;
    print_collection(books);

    // use overloaded < operator    
    //std::sort(std::begin(books),std::end(books));
    //std::sort(std::begin(books),std::end(books),std::less<Book>());
    //std::sort(std::begin(books),std::end(books),std::greater<Book>());
                                                                // Will look for > operator.
                                                                // Put it in and make the compiler
                                                                //happy
    //custom pred
    auto cmp = [](const Book& book1, const Book& book2){
        return (book1.m_year < book2.m_year);
    };
    std::sort(std::begin(books),std::end(books),cmp);
   
    std::cout << "books(after sort) : " << std::endl;
    print_collection(books);
   
    return 0;
}