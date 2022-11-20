#include <iostream>

#include "Ratio.hpp"


int main() {

    Ratio<int> r(4,6) ; 
    Ratio<int> r2(2,1) ; 
 

    r.reduce(); 
    r.display() ; 
    r.pow(3);
    r.display(); 
    r = -r ; 
    r.display() ; 
   r.abs() ; 
   std::cout << "r abs :" << r <<std::endl ;


    Ratio<int> r1 =  Ratio<int>::zero() ; 
   r1.display();

   std::cout << r2*r <<std::endl ;  
   
    return 0;
}
