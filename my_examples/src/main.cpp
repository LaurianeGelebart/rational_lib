#include <iostream>

#include "Ratio.hpp"


int main() {

    Ratio<float> r(4,6) ; 
    Ratio<int> r2(2,10) ; 
 
  std::cout << r*r2 <<std::endl ;


  //  r.reduce(); 

  //std::cout << "r2 pow :" <<  Ratio<int>::pow(r2, 5) <<std::endl ;

    float f = 0.25; 
     Ratio<int> r3 =  Ratio<int>::convert_float_to_ratio(f, 25); 
r3.display() ; 



 //   Ratio<int> r1 =  Ratio<int>::zero() ; 
 //  r1.display();

//   std::cout << r2*r <<std::endl ;  
   
    return 0;
}
