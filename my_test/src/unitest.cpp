#include <random>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>

#include "Ratio.hpp"


/*------------------- CONSTRUCTORS ---------------------*/

TEST (RatioConstructor, defaultConstructor) { 
	Ratio<int> r;
	ASSERT_NE (r.get_denominator(), 0);
}


/*------------------- OPERATOR ---------------------*/


TEST (VectorDArithmetic, multiplication) {
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
		
		r3 = r1 * r2;
		int num = (data1[run]*data3[run]) ; 
		int den = (data2[run]*data4[run]) ; 
		int pgcd = std::gcd(num, den); 

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}

}

TEST (VectorDArithmetic, addition) {
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
		
		r3 = r1 + r2;
		int num = (data1[run]*data4[run]+data3[run]*data2[run]) ; 
		int den = (data2[run]*data4[run]) ; 
		int pgcd = std::gcd(num, den); 

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}

}

TEST (VectorDArithmetic, division) {
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
		
		r3 = r1 / r2;
		int num = (data1[run]*data4[run]) ; 
		int den = (data2[run]*data3[run]) ; 
		int pgcd = std::gcd(num, den); 

		ASSERT_EQ (r3.get_numerator(), num/pgcd);
		ASSERT_EQ (r3.get_denominator(), den/pgcd);
	}

}