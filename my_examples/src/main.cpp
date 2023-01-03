#include <iostream>
#include <chrono>

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
  std::cout << "attention voici un assert : "  << std::endl; 
  inf_r2.inverse(); 

}


void operateur(){
  Ratio<int> r1(1,3);
  Ratio<int> r2(3,4);


  std::cout << "soient r1 : " << r1 << " et soient r2 : " << r2 << std::endl ;

  Ratio<int> copie = r1 ; 
  std::cout << "result copie de r1 : " << copie << std::endl ;

  Ratio<int> resultAdd = r1 + r2; 
  std::cout << "resultat addition r1 + r2: " << resultAdd << std::endl ;

  Ratio<int> resultSou = r2 - r1; 
  std::cout << "result soustraction r2 - r1: " << resultSou << std::endl ;

  Ratio<int> resultMult = r1 * r2; 
  std::cout << "result multiplication r1 * r2 : " << resultMult << std::endl ;

  Ratio<int> resultMultInt = r1 * 5;
  std::cout << "result multiplication par entier r1 * 5: " << resultMultInt << std::endl ;

  Ratio<int> resultdiv = r1 / r2; 
  std::cout << "result division r1 / r2 : " << resultdiv << std::endl ;

  Ratio<int> resultDivInt = r1 / 5;
  std::cout << "result multiplication par entier r1 / 5 : " << resultDivInt << std::endl ;

  bool leq = r1 <= r2 ;
  std::cout << "result inferieur ou egale  r1 <= r2 : " << leq << std::endl ;

  bool lower = r1 < r2 ;
  std::cout << "result inferieur r1 < r2 : " << lower << std::endl ;

  bool heq = r1 >= r2 ;
  std::cout << "result supperieur ou egale r1 >= r2 " << heq << std::endl ;

  bool higher = r1 > r2 ;
  std::cout << "result supperieur r1 > r2: " << higher << std::endl ;

  bool equality = r1 == r2 ;
  std::cout << "result égalité r1 == r2 :" << equality << std::endl ;

  bool not_equal = r1!= r2 ;
  std::cout << "result inégalité r1!= r2 : " << not_equal << std::endl;

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

  // on peut obtenir la valeur absolue d'un ratio
  std::cout << "valeur absolue : " << r.abs() << std::endl ; 

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
  Ratio<int> r(6,5) ;

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  srand(seed);

  // Différentes méthodes de cos
  auto start = std::chrono::steady_clock::now();
  float cos1 = Ratio<int>::cos(r) ; 
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << "cos avec std, résultat : " << cos1 << " temps de calcul : " << elapsed_seconds.count() << "s" << std::endl ; 
  
  start = std::chrono::steady_clock::now();
  float cos2 = Ratio<int>::taylor_cos(r) ; 
  end = std::chrono::steady_clock::now();
  elapsed_seconds = end-start;
  std::cout << "cos par methode de taylor, résultat : " << cos2 << " temps de calcul : " << elapsed_seconds.count() << "s" << std::endl << std::endl ; 

  // mais si on prend une plus grande valeu de cos ça ne fonctionne plus
  Ratio<int> r2(17,2) ; 
  float std_result2 = Ratio<int>::cos(r2) ;
  std::cout << "cos d'une valeur plus grande avec std, résultat : " << std_result2 << " temps de calcul : " << elapsed_seconds.count() << "s" << std::endl ; 
  float our_result2 = Ratio<int> :: taylor_cos(r2);
  std::cout << "cos d'une valeur plus grande par methode de taylor, résultat : " << our_result2 << " temps de calcul : " << elapsed_seconds.count() << "s" << std::endl << std::endl ; 


  // Différentes méthodes de abs
  start = std::chrono::steady_clock::now();
  Ratio<int> abs1 = r.abs() ; 
  end = std::chrono::steady_clock::now();
  elapsed_seconds = end-start;
  std::cout << "valeur absolue avec std, résultat : " << abs1 << " temps de calcul : " << elapsed_seconds.count() << "s" << std::endl ; 

  start = std::chrono::steady_clock::now();
  Ratio<int> abs2 = r.abs2() ; 
  end = std::chrono::steady_clock::now();
  elapsed_seconds = end-start;
  std::cout << "valeur absolue par nous, résultat : " << abs2 << " temps de calcul : " << elapsed_seconds.count() << "s" << std::endl << std::endl; 
   

  // Différentes méthodes de sqrt
  start = std::chrono::steady_clock::now();
  float sqrt1 = Ratio<int>::sqrt2(r) ; 
  end = std::chrono::steady_clock::now();
  elapsed_seconds = end-start;
  std::cout << "square root avec std, résultat : " << sqrt1 << " temps de calcul : " << elapsed_seconds.count() << "s" << std::endl ; 
  
  start = std::chrono::steady_clock::now();
  float sqrt2 = Ratio<int>::sqrt(r) ; 
  end = std::chrono::steady_clock::now();
  elapsed_seconds = end-start;
  std::cout << "square root par nous, résultat : " << sqrt2 << " temps de calcul : " << elapsed_seconds.count() << "s" << std::endl << std::endl; 
  

  // Différentes méthodes de pow
  start = std::chrono::steady_clock::now();
  Ratio<int> pow1 = Ratio<int>::pow(r,3) ; 
  end = std::chrono::steady_clock::now();
  elapsed_seconds = end-start;
  std::cout << "puissance par std, résultat : " << pow1 << " temps de calcul : " << elapsed_seconds.count() << "s" << std::endl ; 
   
  start = std::chrono::steady_clock::now();
  Ratio<int> pow2 = Ratio<int>::pow2(r,3) ; 
  end = std::chrono::steady_clock::now();
  elapsed_seconds = end-start;
  std::cout << "puissance par nous, résultat : " << pow2 << " temps de calcul : " << elapsed_seconds.count() << "s" << std::endl << std::endl; 

  // notre pow ne fonctionne que pour les puissances positives
  std::cout << "attention voici un assert : "  << std::endl; 
  std::cout << "puissance de -3 par nous : " << Ratio<int>::pow2(r,-3)  << std::endl ; 


}




// ---------------------------- LE MAIN EST ICI ---------------------------- //
// Décommentez et testez !
int main() {

// --- Initialisation de ratios --- //
 // initialisation(); 

// --- Opérateurs --- //
   // operateur(); 

// --- Methodes d'un ratio --- //
  // methode(); 

// --- Conversion de ratio --- //
 //  conversion(); 

// --- Comparatif de méthodes --- //
   comparatif(); 

    return 0;
}
