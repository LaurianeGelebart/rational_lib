#include <iostream>

#include "Ratio.hpp"


void initialisation(){
  Ratio<int> default_r ; 
  Ratio<int> basic_r(4,-8) ; 
  Ratio<long int> long_r (22892831, 792301382) ;
  
  // les ratios sont réduits et le moins va au numérateur
  std::cout << "ratio réduit par le constructeur : " << basic_r << std::endl ;
  // le ratio par défaut est 0/1
  std::cout << "ratio réduit par le constructeur : " << default_r << std::endl ;

  // il existe 3 fonctions qui créent 3 ratios particuliers
  Ratio<int> zero_r = Ratio<int>::zero(); 
  Ratio<int> one_r = Ratio<int>::one(); 
  Ratio<int> inf_r = Ratio<int>::inf(); 

  // on peut afficher l'infini
  std::cout << "infini par la fonction inf : " << inf_r << std::endl ;
  // créer un ratio 1/0 
  Ratio<int> inf_r2(1,0) ; 
  // mais il est la réprsentation de l'infini dans la classe
  std::cout << "infini par un dénominateur à 0' : " << inf_r2 << std::endl ;
  // on ne peut pas faire de calcul avec mais le résultat est l'infini aussi
  std::cout << "opération sur l'infini : " << basic_r + inf_r2 << std::endl ; 
  // ni lui appliquer des fonctions 
  inf_r2.inverse(); 

}


void operateur(){

}


void methode(){
  Ratio<int> r(4,7) ; 

  //un ratio a des getters 
  std::cout << "numerateur par getter : " << r.get_numerator() << std::endl ; 
  //un ratio a des setters
  r.set_numerator(8) ; 
  std::cout << "numerateur après setter : " << r.get_numerator() << std::endl ; 

  // un ratio a plusieurs méthodes void
  r.reduce(); 
  r.set_minus(); 
  std::cout << "desplay : "; 
  r.display(); 

  // on peut obtenir l'inverse d'un ratio
  std::cout << "inverse : " << r.inverse() << std::endl ; 

  // un ratio a pleins de fonctions mathématiques 
  std::cout << "puissance : " << Ratio<int>::pow(r,3) << std::endl ; 
  std::cout << "exponentiel : " << Ratio<int>::exp(r) << std::endl ; 
  std::cout << "logarithme : " << Ratio<int>::log(r) << std::endl ; 
  std::cout << "racine carrée : " << Ratio<int>::sqrt(r) << std::endl ; 
  std::cout << "racine nième : " << Ratio<int>::find_name(r,3) << std::endl ; 
  std::cout << "cosinus : " << Ratio<int>::cos(r) << std::endl ; 

  // on peut également utiliser ces methodes à la suite et faire des calculs
  std::cout << "racine carrée de ( 2*(8/7) )^3 = " << Ratio<int>::sqrt(Ratio<int>::pow(2*r,3)) << std::endl ; 

}


void conversion(){
  Ratio<int> r(1,7) ; 
  float f = 0.142857 ; 

  // il existe une méthode pour converti un float en rationnel 
  std::cout << "0.142857 = " <<Ratio<int>::convert_float_to_ratio(f, 5) << std::endl ; 
  // et une méthode qui converti un rationnel en float
  std::cout << "1/7 = " << r.convert_ratio_to_float() << std::endl ; 

  // mais parfois la methode convert_float_to_ratio n'est pas précise 
  std::cout << "3.14159265359 = " << Ratio<int>::convert_float_to_ratio(3.14159265359, 5) << std::endl ; 
  std::cout << "27/7 = " << Ratio<int>(22,7).convert_ratio_to_float() << std::endl ; 

  // elle ne fonctionne plus si les nombres sont trop grand ou trop petit 
  std::cout << "2.9304973e-10 = " << Ratio<int>::convert_float_to_ratio(0.00000000029304973, 5) << std::endl ; 
  std::cout << "-1/-2147483648 = " << Ratio<int>(-1,-2147483648).convert_ratio_to_float() << std::endl ; 

}



void comparatif(){

}




// ---------------------------- LE MAIN EST ICI ---------------------------- //
// Décommentez et testez !
int main() {

// --- Initialisation de ratios --- //
  // initialisation(); 

// --- Opérateurs --- //
  // operator(); 

// --- Methodes d'un ratio --- //
   //methode(); 

// --- Conversion de ratio --- //
  // conversion(); 

// --- Comparatif de méthodes --- //
  // comparatif(); 

    return 0;
}
