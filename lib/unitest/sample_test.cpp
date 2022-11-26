#include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>

#include "VectorD.hpp"


/////////////////////////////////////////////////////
// constructors

TEST (VectorDConstructor, defaultConstructor) { 
	VectorD vec;
	ASSERT_EQ (vec.size(), 0);
}



/////////////////////////////////////////////////////
// arithmetic

TEST (VectorDArithmetic, plus) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim), vec3(dim);
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
			vec2[i] = data2[i];
		}

		vec3 = vec1 + vec2;
		ASSERT_EQ (vec3.size(), dim);

		for(size_t i=0; i<dim; ++i){
	    	ASSERT_DOUBLE_EQ (vec3[i], data1[i] + data2[i]);    // EXPECT_DOUBLE_EQ would be fine too
		}
	}
}


TEST (VectorDArithmetic, minus) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim), vec3(dim);
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
			vec2[i] = data2[i];
		}

		vec3 = vec1 - vec2;
		ASSERT_EQ (vec3.size(), dim);

		for(size_t i=0; i<dim; ++i){
	    	ASSERT_DOUBLE_EQ (vec3[i], data1[i] - data2[i]);  // EXPECT_DOUBLE_EQ would be fine too
		}
	}
}




TEST (VectorDArithmetic, dotCom) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	double product1, product2  ; 

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim);
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
			vec2[i] = data2[i];
		}

		// Commutativité
		product1 = vec1.dot(vec2) ;
		product2 = vec2.dot(vec1) ;
		ASSERT_EQ (product1, product2);

	}
}


TEST (VectorDArithmetic, dot) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	double product1, product2 ; 

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// define a vector dimension
		const size_t dim = 3 ; 

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim);
		product1 = 32 ; 
		vec1[0] = 1.0;
		vec1[1] = 2.0; 
		vec1[2] = 3.0;
		vec2[0] = 4.0;
		vec2[1] = 5.0; 
		vec2[2] = 6.0;

		// valeurs en durs = dot 
		product2 = vec1.dot(vec2) ;
		ASSERT_EQ (product1, product2); 

	}
}
TEST (VectorDArithmetic, dotOtherMethode) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	double product1, product2; 

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim);
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
			vec2[i] = data2[i];
		}

		// my dot == dot()
		for(long unsigned int i=0; i< dim ; i++){
				product1 += vec1[i]*vec2[i] ; 
        }
		product2 = vec1.dot(vec2) ;
		ASSERT_EQ (product1, product2); 

	}
}

TEST (VectorDArithmetic, dotPositiv) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	double product1 ; 

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim);
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
			vec2[i] = data2[i];
		}

		// U.V >= 0
		product1 = vec1.dot(vec2) ;
		ASSERT_GE (product1, 0); 

	}
}

TEST (VectorDArithmetic, dotCos) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	double product1, product2  ; 

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim);
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
			vec2[i] = data2[i];
		}

		// U.V == 0.5(U²+V²-(U-V)²)  
		product1 = vec1.dot(vec2) ; 
		ASSERT_EQ (product1, 0.5*(vec1.dot(vec1) + vec2.dot(vec2) - (vec1 - vec2).dot((vec1 - vec2))));    

	}
}


TEST (VectorDArithmetic, product) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	double product1, product2  ; 

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim);
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
		}

		//  
		 
		for(size_t i=0; i<dim; ++i){
			vec2 = vec1[i]*i ;
	    	ASSERT_DOUBLE_EQ (, );  // EXPECT_DOUBLE_EQ would be fine too
		}  

	}
}



/////////////////////////////////////////////////////
// exception

TEST (VectorDException, loadExceptionMessage) {
	const std::string filename = "filename.txt";
	const std::string expectedException = "VectorD::load: error: can not open file: " + filename;

	// check the exception message
    try{
		VectorD vec;
        vec.load(filename);
    }
    catch( const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find(expectedException) == 0);
    }
}


TEST (VectorDException, loadExceptionType) {

	// check exception type
	VectorD vec;
	EXPECT_THROW(vec.load("filename.txt"), std::ios_base::failure);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


