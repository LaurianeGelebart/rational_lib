#include <random>
#include <fstream>
#include <algorithm>
#include <cmath>

#include <gtest/gtest.h>

#include "Ratio.hpp"


constexpr double epsilon = 0.0001;


/*------------------- CONSTRUCTORS ---------------------*/

TEST (RatioConstructor, default_constructor) { 
	Ratio<long int> r;
	ASSERT_EQ (r.get_numerator(), 0);
}

TEST (RatioConstructor, constructor_int) { 
	Ratio<int> r(2,7);
	ASSERT_EQ (r.get_numerator(), 2);
}

TEST (RatioConstructor, constructor_long_int) { 
	Ratio<long int> r(228389928103,6);
	ASSERT_EQ (r.get_numerator(), 228389928103);
}


/*------------------- OPERATOR ---------------------*/


TEST (RatioArithmetic, multiplication) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =100 ; 
	Ratio<long int> r1, r2, r3;

	std::vector<long int> data1(nbTest), data2(nbTest), data3(nbTest), data4(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);
	std::generate(data3.begin(), data3.end(), gen);
	std::generate(data4.begin(), data4.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one();
		r2 = Ratio<long int>::one();
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 
		r2.set_numerator(data3[run]);
		r2.set_denominator(data4[run]) ; 
		
		r3 = r1 * r2;
		long int num = (data1[run]*data3[run]) ; 
		long int den = (data2[run]*data4[run]) ; 
		long int pgcd = std::gcd(num, den); 

		if((num > 0 && den < 0 ) || (num < 0 && den < 0 ) ){
			num = -num ; 
			den = -den ; 
		}

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}

}

TEST (RatioArithmetic, addition) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =100 ; 
	Ratio<long int> r1, r2, r3;

	std::vector<long int> data1(nbTest), data2(nbTest), data3(nbTest), data4(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);
	std::generate(data3.begin(), data3.end(), gen);
	std::generate(data4.begin(), data4.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one();
		r2 = Ratio<long int>::one();
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 
		r2.set_numerator(data3[run]);
		r2.set_denominator(data4[run]) ; 
		
		r3 = r1 + r2;
		long int num = (data1[run]*data4[run]+data3[run]*data2[run]) ; 
		long int den = (data2[run]*data4[run]) ; 
		long int pgcd = std::gcd(num, den); 

		if((num > 0 && den < 0 ) || (num < 0 && den < 0 ) ){
			num = -num ; 
			den = -den ; 
		}

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}

}

TEST (RatioArithmetic, division) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =100 ; 
	Ratio<long int> r1, r2, r3;

	std::vector<long int> data1(nbTest), data2(nbTest), data3(nbTest), data4(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);
	std::generate(data3.begin(), data3.end(), gen);
	std::generate(data4.begin(), data4.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one();
		r2 = Ratio<long int>::one();
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 
		r2.set_numerator(data3[run]);
		r2.set_denominator(data4[run]) ; 
		
		r3 = r1 / r2;
		long int num = (data1[run]*data4[run]) ; 
		long int den = (data2[run]*data3[run]) ; 
		long int pgcd = std::gcd(num, den); 

		if((num > 0 && den < 0 ) || (num < 0 && den < 0 ) ){
			num = -num ; 
			den = -den ; 
		}

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}

}

TEST (RatioArithmetic, soustraction) {
	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<long int> uniformIntDistribution(1,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest = 100 ; 
	Ratio<long int> r1, r2, r3;

	std::vector<long int> data1(nbTest), data2(nbTest), data3(nbTest), data4(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);
	std::generate(data3.begin(), data3.end(), gen);
	std::generate(data4.begin(), data4.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one();
		r2 = Ratio<long int>::one();
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 
		r2.set_numerator(data3[run]);
		r2.set_denominator(data4[run]) ; 
		
		r3 = r1 - r2;
		long int num = (data1[run]*data4[run]-data3[run]*data2[run]) ; 
		long int den = (data2[run]*data4[run]) ; 
		long int pgcd = std::gcd(num, den); 

		if((num > 0 && den < 0 ) || (num < 0 && den < 0 ) ){
			num = -num ; 
			den = -den ; 
		}

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}
}



/**/
TEST(VectorDArithmetic, double_equals){
	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<long int> uniformIntDistribution(1,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest = 100 ; 
	Ratio<long int> r1, r2, r3;
	

	std::vector<long int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);
	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one();
		r2 = Ratio<long int>::one();
		r1.set_numerator(data1[run]);
		r1.set_denominator(data2[run]); 
		r2.set_numerator(data1[run]);
		r2.set_denominator(data2[run]); 
		
		bool equality = (r1 == r2); //renvoie un bool
		bool not_equality = (r2 == r3);

		ASSERT_EQ(equality ,true); //verifie si le bool renvoyer est bien true
		ASSERT_EQ(not_equality, false); //prouve que sans l'opérateur = c'est forcément faux.
	}
}

TEST (VectorDArithmetic, equals) {
	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<long int> uniformIntDistribution(1,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest = 100 ; 
	Ratio<long int> r1, r2, r3;
	

	std::vector<long int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);
	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one();
		r1.set_numerator(data1[run]);
		r1.set_denominator(data2[run]); 
		
		r2 = r1;
		bool equality = (r1 == r2); //renvoie un bool
		bool not_equality = (r2 == r3);

		ASSERT_EQ(equality ,true); //verifie si le bool renvoyer est bien true
		ASSERT_EQ(not_equality, false); //prouve que sans l'opérateur = c'est forcément faux.
	}

}

TEST (VectorDArithmetic, lower_equal){
	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<long int> uniformIntDistribution(1,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	//déclaration des variables
	Ratio<long int> r1(1,2);
	Ratio<long int> r2(3,2);
		
	//on vérifie les cas où la fonction marche	
	bool lower = (r1 <= r2); //on test l'infériorité
	//ou
	bool equal = (r1 <= r1); //on teste l'égalité

	//cas où elle ne marche pas
	bool upper = (r2 <= r1);

	//Assert sur les résultats.
	ASSERT_EQ(lower ,true); //verifie si le bool renvoyer est bien true
	ASSERT_EQ(equal, true);
	ASSERT_EQ(upper, false);
	
	
}

TEST (VectorDArithmetic, upper_equal){
	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<long int> uniformIntDistribution(1,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	//déclaration des variables
	Ratio<long int> r1(1,2);
	Ratio<long int> r2(3,2);
		
	//on vérifie les cas où la fonction marche	
	bool upper = (r2 >= r1); //on test la supériorité
	//ou
	bool equal = (r2 >= r2); //on teste l'égalité

	//cas où elle ne marche pas
	bool lower = (r1 >= r2);

	//Assert sur les résultats.
	ASSERT_EQ(upper ,true); //verifie si le bool renvoyer est bien true
	ASSERT_EQ(equal, true);
	ASSERT_EQ(lower, false);
	
}

 TEST (VectorDArithmetic, lower_to){
	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<long int> uniformIntDistribution(1,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	//déclaration des variables
	Ratio<long int> r1(1,2);
	Ratio<long int> r2(3,2);
	

	//on vérifie les cas où la fonction marche	
	bool lower = (r1 < r2); //on test l'infériorité

	//cas où elle ne marche pas
	bool upper = (r2 < r1); //on teste la supériorité

	//Assert sur les résultats.
	ASSERT_EQ(lower ,true); //verifie si le bool renvoyer est bien true
	ASSERT_EQ(upper, false);
	
}
 

TEST (VectorDArithmetic, upper_to){
	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<long int> uniformIntDistribution(1,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	//déclaration des variables
	Ratio<long int> r1(1,2);
	Ratio<long int> r2(3,2);
		
	//on vérifie les cas où la fonction marche	
	bool upper = (r2 > r1); //on test la supériorité

	//cas où elle ne marche pas
	bool lower = (r1 > r2); //on teste l'infériorité

	//Assert sur les résultats.
	ASSERT_EQ(upper ,true); //verifie si le bool renvoyer est bien true
	ASSERT_EQ(lower, false);
	
}

TEST (VectorDArithmetic, cosinus){
	const size_t maxSize = 100;  
	const size_t minSize = -100;   
	std::mt19937 generator(0);
	std::uniform_int_distribution<long int> uniformIntDistribution(1,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest = 10 ; 
	Ratio<long int> r;
	float test1, test2, eps;

	std::vector<long int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);


	for(int run=0; run<nbTest; ++run){
		r = Ratio<long int>::one();
		r.set_numerator(data1[run]) ;
		r.set_denominator(data2[run]) ; 

		test1 = std::cos((float)data1[run]/(float)data2[run]);
		test2 = Ratio<long int>::taylor_cos(r);
		eps = std::abs(test2 - test1);
		ASSERT_LE(eps,0.01);	

	}

}


/*------------------- METHODE ---------------------*/

TEST (RatioMethode, reduce) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =100 ; 
	Ratio<long int> r1, r2;

	std::vector<long int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one();
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 

		r2 = r1 ; 
		r1.reduce() ;
		
		ASSERT_EQ (r1.convert_ratio_to_float(), r2.convert_ratio_to_float());
	}

}

TEST (RatioMethode, power) {
	const size_t maxSize = 100;  
	const size_t minSize = -100;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =100 ; 
	Ratio<long int> r;
	float f1, f2 ; 

	std::vector<long int> data1(nbTest), data2(nbTest), data3(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r = Ratio<long int>::one();
		r.set_numerator(data1[run]) ;
		r.set_denominator(data2[run]) ; 

		r = Ratio<long int>::pow(r, data3[run]); 
		f1 = std::pow((float)data1[run], data3[run]);  
		f2 = std::pow((float)data2[run], data3[run]); 
		
		ASSERT_EQ (r.get_numerator(), f1);
		ASSERT_EQ (r.get_denominator(), f2);
	}
}

TEST (RatioMethode, inverse) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =100 ; 
	Ratio<long int> r1, r2;

	std::vector<long int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one();
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 

		r2 = r1.inverse() ;
		
		ASSERT_EQ (std::abs(r2.get_numerator()), r1.get_denominator());
		ASSERT_EQ (r2.get_denominator(), std::abs(r1.get_numerator()));
	}
}

TEST (RatioMethode, ratio_to_float) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =100 ; 
	Ratio<long int> r1;
	float f ; 

	std::vector<long int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one();
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ;

		f = (float)data1[run]/(float)data2[run]; 
		
		ASSERT_EQ (r1.convert_ratio_to_float(), f);
	}
}

TEST (RatioMethode, float_to_ratio) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =100 ; 
	Ratio<long int> r1;
	float f ; 

	std::vector<long int> data1(nbTest);
	std::generate(data1.begin(), data1.end(), gen);

	for(int run=0; run<nbTest; ++run){
		f = data1[run]; 
		r1 = Ratio<long int>::convert_float_to_ratio(f, 25) ;
		
		ASSERT_EQ (r1.convert_ratio_to_float(), f);
	}

}

TEST (RatioMethode, exponantial) {
	const size_t maxSize = 100;  
	const size_t minSize = -100;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =100 ; 
	Ratio<long int> r1;
	float f1, f2, delta ; 
	int puissancef1, puissancef2 ; 

	std::vector<long int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one();  
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ;

		f1 = Ratio<long int>::exp(r1);
		f2 = std::exp((float)data1[run] / (float)data2[run]) ; 
				
		delta = std::abs(f1 - f2) ;
		puissancef1 = std::log10(f1); 
		puissancef2 = std::log10(f2); 
		if (puissancef1>puissancef2) delta /= std::pow(10,puissancef1) ; 
		else delta /= std::pow(10,puissancef2) ; 

		ASSERT_LT (delta, epsilon);		
	}

}


TEST (RatioMethode, logarithm) {
	const size_t maxSize = 100;  
	const size_t minSize = 1;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =10 ; 
	Ratio<long int> r1;
	float f1, f2, delta ; 
	int puissancef1, puissancef2 ; 

	std::vector<long int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one(); 
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ;

		f1 = Ratio<long int>::log(r1);
		f2 = std::log((float)data1[run] / (float)data2[run]) ; 
		
		delta = std::abs(f1 - f2) ;
	//	puissancef1 = std::log10(f1);    CA MARCHE PAS 
	//	puissancef2 = std::log10(f2); 
	//	if (puissancef1>puissancef2) delta /= std::pow(10,puissancef1) ; 
	//	else delta /= std::pow(10,puissancef2) ; 

		ASSERT_EQ (puissancef2, epsilon);
	}
}

TEST (RatioMethode, square_root) {
	const size_t maxSize = 1000;  
	const size_t minSize = 1;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<long int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =100 ; 
	Ratio<long int> r1;
	float f1, f2 , delta; 
	int puissancef1, puissancef2 ; 

	std::vector<long int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<long int>::one(); 
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ;

		f1 = Ratio<long int>::sqrt(r1);
		f2 = std::sqrt((float)data1[run] / (float)data2[run]) ; 
		
		delta = std::abs(f1 - f2) ;
		puissancef1 = std::log10(f1); 
		puissancef2 = std::log10(f2); 
		if (puissancef1>puissancef2) delta /= std::pow(10,puissancef1) ; 
		else delta /= std::pow(10,puissancef2) ; 

		ASSERT_LE (delta, epsilon);
	}
}


TEST (RatioMethode, find_name) {
	const size_t maxSize = 100;  
	const size_t minSize = 1;  
	std::mt19937 generator(0);
	std::uniform_int_distribution< int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	const size_t nbTest =10 ; 
	Ratio< int> r1;
	float f1, f2 , delta; 
	int puissancef1, puissancef2 ; 

	std::vector< int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1 = Ratio<int>::one(); 
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ;

		f1 = Ratio< int>::find_name(r1, run);
		f2 = std::pow((float)data1[run] / (float)data2[run], 1.0/(float)run) ; 
		
		delta = std::abs(f1 - f2) ;
		puissancef1 = std::log10(f1); 
		puissancef2 = std::log10(f2); 
		if (puissancef1>puissancef2) delta /= std::pow(10,puissancef1) ; 
		else delta /= std::pow(10,puissancef2) ;  

		ASSERT_EQ (f1, f2);
	}
}

