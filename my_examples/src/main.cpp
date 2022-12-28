#include <iostream>

#include "Ratio.hpp"

//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




int main() {

  Ratio<int> r(4,8) ; 
  Ratio<long int> r2(6.3,4.4) ; 
  Ratio<long int> result;

  result = 2*r2.inverse();
  

  std::cout<<r2<<std::endl;





    //--------- Etude du problème de convert_float_to_ratio -----------//

   // La ça marche  
 //  Ratio<int> r3 = Ratio<int>::convert_float_to_ratio(0.0000000029304973, 3) ; 
  // Là ça ne marche pas  
 //  Ratio<int> r3 = Ratio<int>::convert_float_to_ratio(0.00000000029304973, 3) ; 

   // La ça marche  
 //  Ratio<int> r3 = Ratio<int>::convert_float_to_ratio(298910944.3, 3) ; 
  // Là ça ne marche pas  
 //  Ratio<int> r3 = Ratio<int>::convert_float_to_ratio(2989810944.3, 3) ; 




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
