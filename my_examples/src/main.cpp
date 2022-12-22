#include <iostream>

#include "Ratio.hpp"

//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

int main() {

  Ratio<int> r(4,8) ; 
  Ratio<int> r2(6,4) ; 
  Ratio<int> result;

  result = r-r2;

  std::cout<<result<<std::endl;





    //--------- Etude du problème de convert_float_to_ratio -----------//

   // La ça marche  
 //  Ratio<int> r3 = Ratio<int>::convert_float_to_ratio(0.0000000029304973, 3) ; 
  // Là ça ne marche pas  
 //  Ratio<int> r3 = Ratio<int>::convert_float_to_ratio(0.00000000029304973, 3) ; 

   // La ça marche  
 //  Ratio<int> r3 = Ratio<int>::convert_float_to_ratio(298910944.3, 3) ; 
  // Là ça ne marche pas  
 //  Ratio<int> r3 = Ratio<int>::convert_float_to_ratio(2989810944.3, 3) ; 



   Ratio<int> r3 = Ratio<int>::convert_float_to_ratio(-2, 3) ; 

 
  std::cout << r3 << std::endl ; 

  Ratio<int> r4 = Ratio<int>(3,0); 

  std::cout << std::pow(std::exp(3),3.0/0.0) << std::endl ; 
  std::cout << Ratio<int>::exp(r4) << std::endl ; 




  //  r2.reduce() ; 
  //  std::cout << r2 << std::endl ; 
 // std::cout << Ratio<int>::pow(r,5) << std::endl ; 

 //   Ratio<int> r3 ; 
   // std::cout << r3.get_numerator() << std::endl ; 
 
//  std::cout << r.abs()*r2 <<std::endl ;
  //  static_assert ( (r.abs()) == r3 , "test of abs ’ at compile time" ) ; 


  //  r.reduce(); 

  //std::cout << "r2 pow :" <<  Ratio<int>::pow(r2, 5) <<std::endl ;

  //  float f = 0.25; 
  //   Ratio<int> r3 =  Ratio<int>::convert_float_to_ratio(f, 25); 
//r3.display() ; 



 //   Ratio<int> r1 =  Ratio<int>::zero() ; 
 //  r1.display();

//   std::cout << r2*r <<std::endl ;  
   
    return 0;
}
