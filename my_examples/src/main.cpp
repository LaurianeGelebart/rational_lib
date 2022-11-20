#include <iostream>

#include "Ratio.hpp"


int main() {

    Ratio<int> r(4,6) ; 
 

    r.reduce(); 
    r.display() ; 
    r.pow(-2);

    r.display(); 
  //  Ratio<int> r1 =  Ratio<int>::zero() ; 
  //  r1.display();
    return 0;
}
