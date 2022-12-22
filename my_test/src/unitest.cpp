#include <random>
#include <fstream>
#include <algorithm>
#include <cmath>

#include <gtest/gtest.h>

#include "Ratio.hpp"


constexpr double epsilon = 0.001;


/*------------------- CONSTRUCTORS ---------------------*/

TEST (RatioConstructor, defaultConstructor) { 
	Ratio<int> r;
	ASSERT_NE (r.get_denominator(), 0);
}

TEST (RatioConstructor, constructorInt) { 
	Ratio<int> r(2,6);
	ASSERT_NE (r.get_denominator(), 2);

}


/*------------------- OPERATOR ---------------------*/


TEST (RatioArithmetic, multiplication) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =100 ; 
	Ratio<int> r1, r2, r3;

	std::vector<int> data1(nbTest), data2(nbTest), data3(nbTest), data4(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);
	std::generate(data3.begin(), data3.end(), gen);
	std::generate(data4.begin(), data4.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 
		r2.set_numerator(data3[run]);
		r2.set_denominator(data4[run]) ; 
		
		r3 = r1 * r2;
		int num = (data1[run]*data3[run]) ; 
		int den = (data2[run]*data4[run]) ; 
		int pgcd = std::gcd(num, den); 

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}

}

TEST (RatioArithmetic, addition) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =100 ; 
	Ratio<int> r1, r2, r3;

	std::vector<int> data1(nbTest), data2(nbTest), data3(nbTest), data4(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);
	std::generate(data3.begin(), data3.end(), gen);
	std::generate(data4.begin(), data4.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 
		r2.set_numerator(data3[run]);
		r2.set_denominator(data4[run]) ; 
		
		r3 = r1 + r2;
		int num = (data1[run]*data4[run]+data3[run]*data2[run]) ; 
		int den = (data2[run]*data4[run]) ; 
		int pgcd = std::gcd(num, den); 

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}

}

TEST (RatioArithmetic, division) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =100 ; 
	Ratio<int> r1, r2, r3;

	std::vector<int> data1(nbTest), data2(nbTest), data3(nbTest), data4(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);
	std::generate(data3.begin(), data3.end(), gen);
	std::generate(data4.begin(), data4.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 
		r2.set_numerator(data3[run]);
		r2.set_denominator(data4[run]) ; 
		
		r3 = r1 / r2;
		int num = (data1[run]*data4[run]) ; 
		int den = (data2[run]*data3[run]) ; 
		int pgcd = std::gcd(num, den); 

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}

}

TEST (RatioArithmetic, soustraction) {
	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest = 100 ; 
	Ratio<int> r1, r2, r3;

	std::vector<int> data1(nbTest), data2(nbTest), data3(nbTest), data4(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);
	std::generate(data3.begin(), data3.end(), gen);
	std::generate(data4.begin(), data4.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 
		r2.set_numerator(data3[run]);
		r2.set_denominator(data4[run]) ; 
		
		r3 = r1 - r2;
		int num = (data1[run]*data4[run]-data3[run]*data2[run]) ; 
		int den = (data2[run]*data4[run]) ; 
		int pgcd = std::gcd(num, den); 

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}
}


/*------------------- METHODE ---------------------*/

TEST (RatioMethode, reduce) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =100 ; 
	Ratio<int> r1, r2;

	std::vector<int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 

		r2 = r1 ; 

		r1.reduce() ;
		
		ASSERT_EQ (r1.convert_ratio_to_float(), r2.convert_ratio_to_float());
	}

}

TEST (RatioMethode, inverse) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =100 ; 
	Ratio<int> r1, r2;

	std::vector<int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ; 

		r2 = r1.inverse() ;
		r1.reduce(); 
		
		ASSERT_EQ (r2.get_numerator(), r1.get_denominator());
		ASSERT_EQ (r2.get_denominator(), r1.get_numerator());
	}

}

TEST (RatioMethode, ratio_to_float) {
	const size_t maxSize = 1000;  
	const size_t minSize = -1000;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =100 ; 
	Ratio<int> r1;
	float f ; 

	std::vector<int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
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
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =100 ; 
	Ratio<int> r1;
	float f ; 

	std::vector<int> data1(nbTest);
	std::generate(data1.begin(), data1.end(), gen);

	for(int run=0; run<nbTest; ++run){
		f = data1[run]; 
		r1 = Ratio<int>::convert_float_to_ratio(f, 25) ;
		
		ASSERT_EQ (r1.convert_ratio_to_float(), f);
	}

}

TEST (RatioMethode, exponantial) {
	const size_t maxSize = 100;  
	const size_t minSize = -100;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =100 ; 
	Ratio<int> r1;
	float f1, f2 ; 

	std::vector<int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ;

		f1 = Ratio<int>::exp(r1);
		f2 = std::exp((float)data1[run] / (float)data2[run]) ; 
		
		ASSERT_EQ (f1, f2);
	}

}


TEST (RatioMethode, logarithm) {
	const size_t maxSize = 1000;  
	const size_t minSize = 1;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =100 ; 
	Ratio<int> r1;
	float f1, f2 ; 

	std::vector<int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ;

		f1 = Ratio<int>::log(r1);
		f2 = std::log((float)data1[run] / (float)data2[run]) ; 
		
		ASSERT_EQ (f1, f2);
	}
}

TEST (RatioMethode, square_root) {
	const size_t maxSize = 1000;  
	const size_t minSize = 1;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =100 ; 
	Ratio<int> r1;
	float f1, f2 ; 

	std::vector<int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ;

		f1 = Ratio<int>::sqrt(r1);
		f2 = std::sqrt((float)data1[run] / (float)data2[run]) ; 
		
		ASSERT_EQ (f1, f2);
	}
}


TEST (RatioMethode, find_name) {
	const size_t maxSize = 1000;  
	const size_t minSize = 0;  
	std::mt19937 generator(3);
	std::uniform_int_distribution<int> uniformIntDistribution(minSize,maxSize);
	auto gen = [&uniformIntDistribution, &generator](){ return uniformIntDistribution(generator);};

	int nbTest =1000 ; 
	Ratio<int> r1;
	float f1, f2 ; 

	std::vector<int> data1(nbTest), data2(nbTest);
	std::generate(data1.begin(), data1.end(), gen);
	std::generate(data2.begin(), data2.end(), gen);

	for(int run=0; run<nbTest; ++run){
		r1.set_numerator(data1[run]) ;
		r1.set_denominator(data2[run]) ;

		f1 = Ratio<int>::find_name(r1, run);
		f2 = std::pow((float)data1[run] / (float)data2[run], 1.0/(float)run) ; 
		
		ASSERT_EQ (f1, f2);
	}
}

