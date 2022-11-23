#include <iostream>

#include "Ratio.hpp"


int main() {

    Ratio<int> r(4,6) ; 
    Ratio<int> r2(2,1) ; 
 

    r.reduce(); 

//   std::cout << "r abs :" << r <<std::endl ;

    float f = 0.25; 
     Ratio<int> r3 =  Ratio<int>::convert_float_to_ratio(f, 25); 
r3.display() ; 

 //   Ratio<int> r1 =  Ratio<int>::zero() ; 
 //  r1.display();

//   std::cout << r2*r <<std::endl ;  
   
    return 0;
}
