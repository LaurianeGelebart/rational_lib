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

