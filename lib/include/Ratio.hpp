#pragma once
#include <numeric>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cassert>



/// @class Ratio 
/// @brief class defining a ratio to represent a real number by a quotient of 2 integers
/// @tparam T can be : int, long int
template<class T>
class Ratio {

private : 
	/// @brief numerator of the ratio 
	T _numerator ; 
    /// @brief denominator of the ratio 
    T _denominator;

public :

/*------------------- CONSTRUCT0R ---------------------*/

	//// @brief constructor from a numerator and a denominator and default constructor
	/// @param _denominator : numerator of the ratio (default : 0.0)
	/// @param _numerator : denominator of the ratio (default : 1.0)
    Ratio(const T num=0.0, const T den = 1.0){
		static_assert(std::is_integral<T>::value, "Integral required.");
		this->_numerator = num ; 
		this->_denominator = den ; 
		this->reduce() ;
		this->set_minus() ;
	}

	/// @brief copy-constructor
	/// @param r source ratio to be copied
	Ratio(const Ratio &r) = default;

    /// @brief destructor
    ~Ratio() = default;


/*------------------- GETTERS ---------------------*/
	
	/// @brief getter of the ratio numerator 
	/// @return numerator of the current ratio
	constexpr T get_numerator() 
	noexcept{
		return this->_numerator ; 
	} 
	
	/// @brief getter of the ratio denominator 
	/// @return denominator of the current ratio
	constexpr T get_denominator() 
	noexcept{
		return this->_denominator ; 
	}

	/// @brief setter of the ratio numerator
	/// @param num numerator of the current ratio
	constexpr void set_numerator(T num)
	noexcept{
		this->_numerator = num ; 
		this->reduce(); 
		this->set_minus(); 
	}

	/// @brief setter of the ratio denominator 
	/// @param den denominator of the current ratio
	constexpr void set_denominator(T den)
	noexcept{
		this->_denominator = den; 
		this->reduce(); 
		this->set_minus(); 
	}


/*------------------- OPERATOR ---------------------*/

    /// @brief affectation operator
    /// @param r ratio affetct to the calling ratio 
    constexpr Ratio& operator=(const Ratio &r)
	noexcept{
		if(&r == this) return *this;
		this->_denominator = r._denominator;
		this->_numerator = r._numerator;
		return *this;
	}

	/// @brief add 2 ratio of the same type
    /// @param r ratio to add to the calling ratio 
    /// @return the sum of the current ratio and the argument ratio
    constexpr Ratio operator+ (const Ratio& r)
	noexcept{
		Ratio<T> result(this->_numerator*r._denominator+this->_denominator*r._numerator, this->_denominator*r._denominator); 
		result.reduce() ; 
		result.set_minus() ; 
		return result; 
	}

    constexpr Ratio operator- (const Ratio& r)
	noexcept{
		Ratio<T> result(this->_numerator*r._denominator-this->_denominator*r._numerator, this->_denominator*r._denominator); 
		result.reduce() ; 
		result.set_minus() ; 
		return result; 
	}

    /// @brief multiply 2 ratio of the same type
    /// @param r ratio to multiply to the calling ratio 
    /// @return a ratio corresponding to the multiplication of the current ratio and the argument ratio
    constexpr Ratio operator* (const Ratio& r) 
	noexcept{
		Ratio<T> result((this->_numerator*r._numerator), (this->_denominator*r._denominator)) ; 
		result.reduce() ; 
		result.set_minus() ; 
		return result; 
	}

    /// @brief multiply a rational and a int
    /// @param nb int to multiply to the calling ratio
    /// @return a ratio corresponding to the multiplication of the current ratio and the argument int
    constexpr Ratio operator* (const int nb){	
		Ratio<T> result((this->_numerator*nb),(this->_denominator));
		result.reduce();
		result.set_minus() ; 
		return result;
	}

    /// @brief divide 2 ratio of the same type
    /// @param r ratio to divide to the calling ratio 
    /// @return a ratio corresponding to the division of the current ratio and the argument ratio
	constexpr Ratio operator/ (const Ratio& r){	
		assert( (this->_denominator != 0) && "error: the denominator is null");
		assert( (r._numerator != 0) && "error: the denominator is null");
		Ratio<T> result((this->_numerator * r._denominator), (this->_denominator * r._numerator));
		result.reduce() ; 
		result.set_minus() ; 
		return result; 
}

	/// @brief divide ratio with a number 
	/// @param nb nb to divide to the calling ratio 
	/// @return a ratio corresponding to the division of the current ratio and the argument number
	constexpr Ratio operator/(const int nb){
		assert( (this->_denominator != 0) && "error: the denominator is null");
		assert( (nb != 0) && "error: the denominator is null");
		Ratio<T> result(this->_numerator, (this->_denominator * nb));
		result.reduce() ; 
		result.set_minus() ; 
		return result; 
	}

    /// @brief unary minus
    /// @return the minus the calling ratio 
    constexpr Ratio operator- () 
	noexcept{	
		Ratio<T> result(-this->_numerator, this->_denominator) ; 
		result.reduce() ; 
		result.set_minus() ; 
		return result; 
	} 

    /// @brief verifies equality between two ratio
    /// @param r ratio which is equal to the other
    /// @return a boolean indicating whether the ratio is equal to the argument ratio
    constexpr bool operator== (const Ratio& r) 
	noexcept{
		return this->_numerator == r._numerator && this->_denominator == r._denominator ? true : false;
	}

	/// @brief verifies equality between two ratio
    /// @param r ratio which is not equal to the other
    /// @return a boolean indicating whether the ratio is not equal to the argument ratio
    constexpr bool operator!= (const Ratio& r) 
	noexcept{
		return this->_numerator != r._numerator && this->_denominator != r._denominator ? true : false;
	}

	/// @brief verifies if the argument is lower or equal to the calling ratio
    /// @param r ratio which is lower or equal to the other
    /// @return a boolean indicating whether the ratio is lower or equal to the argument ratio
    constexpr bool operator<= (const Ratio& r)
	noexcept{
		Ratio<T> result = (*this - r);
		return result._numerator <= 0  ? true : false;
	}

	/// @brief verifies if the argument is higher or equal to the calling ratio
    /// @param r ratio which is higher or equal to the other
    /// @return a boolean indicating whether the ratio is higher or equal to the argument ratio
    constexpr bool operator>= (const Ratio& r) 
	noexcept{
		Ratio<T> result = (*this - r);
		return result._numerator >= 0 ? true : false;
	}

	/// @brief verifies if the argument is lower to the calling ratio
    /// @param r ratio which is lower to the other
    /// @return a boolean indicating whether the ratio is lower to the argument ratio
    constexpr bool operator< (const Ratio& r) 
	noexcept{
		Ratio<T> result = (*this - r);
		return result._numerator < 0  ? true : false;
	}

	/// @brief verifies if the argument is higher  to the calling ratio
    /// @param r ratio which is higher  to the other
    /// @return a boolean indicating whether the ratio is higher  to the argument ratio
    constexpr bool operator> (const Ratio& r) 
	noexcept{
		Ratio<T> result = (*this - r);
		return result._numerator > 0 ? true : false;
	}



/*------------------- METHODES ---------------------*/

	/// @brief display the ratio
    constexpr void display() const 
	noexcept{
		if (this->_denominator == 0)  std::cout << "inf" << std::endl ; 
		else std::cout << this->_numerator << "/" << this->_denominator << std::endl;
	}

	/// @brief reduce the ratio to its irreducible form
	constexpr void reduce() 
	noexcept{
		T pgcd = std::gcd(this->_numerator, this->_denominator); 
		this->_numerator = this->_numerator/pgcd; 
		this->_denominator = this->_denominator/pgcd; 
	}

	/// @brief if the ratio is negative, put the sign on the numerator
	constexpr void set_minus() 
	noexcept{
		if((this->_numerator > 0 && this->_denominator < 0 )
		|| (this->_numerator < 0 && this->_denominator < 0 ) ){
			this->_numerator = -this->_numerator ; 
			this->_denominator = -this->_denominator ; 
		}
	}

	/// @brief find the absolute value of a ratio, function with std 
    /// @return the absolute value the calling ratio 
	constexpr Ratio abs() 
	noexcept{
		return Ratio<T>( std::abs(this->_numerator) , this->_denominator); 
	}

	/// @brief find the absolute value of a ratio, our function without std
    /// @return the absolute value the calling ratio 
	constexpr Ratio abs2() 
	noexcept{
		return (this->_numerator < static_cast<T>(0)) ? Ratio<T>( -this->_numerator , this->_denominator) : Ratio<T>(this->_numerator, this->_denominator) ;	
	}


	/// @brief convert a ratio to a float rumber 
	/// @return the ratio converted into a float
	constexpr float convert_ratio_to_float() 
	noexcept{
		return (float)((float)this->_numerator / (float)this->_denominator) ; 
	}

	/// @brief inverse a ratio 
	/// @return the inverted ratio 
	constexpr Ratio inverse() 
	noexcept{
		assert( (this->_denominator != 0) && "error: the denominator is null, impossible to inverse inf");
		assert( (this->_numerator != 0) && "error: the numerator is null, impossible to inverse this ratio");
		Ratio<T> result = Ratio<T>(this->_denominator, this->_numerator) ; 
		result.set_minus(); 
		return result; 
	}


/*------------------- STATIC METHODES ---------------------*/

	/// @brief the zero-valued rational
	/// @return 0.0/1.0
	constexpr static Ratio zero() 
	noexcept{
		return Ratio<T>(0.0,1.0); 
	}

	/// @brief the rational corresponding to the value one
	/// @return 1.0/1.0
	constexpr static Ratio one() 
	noexcept{
		return Ratio<T>(1.0,1.0); 
	}

	/// @brief the rational correspondind to infinity
	/// @return 1.0/0.0
	constexpr static Ratio inf() 
	noexcept{
		return Ratio<T>(1.0,0.0); 
	}

	/// @brief convert a real number to a Ratio
	/// @param x the real to convert to ratio 
	/// @param nb_iter number of recursive call 
	/// @return  the real converted into a rational 
	constexpr static Ratio convert_float_to_ratio(const float x, const int nb_iter) 
	noexcept{
		if (x==0 || nb_iter==0) return zero() ;
		if (x<0){
			return -(convert_float_to_ratio(-x,nb_iter));
		}
		if(x<1){
			return Ratio<T>(1.0, (convert_float_to_ratio( (float)1.0/x, nb_iter ).convert_ratio_to_float()) ); 
		}
		float q = (int)x; 
		Ratio<T> result(Ratio<T>(q,1.0) + convert_float_to_ratio(x-q, nb_iter-1)); 
		result.reduce() ; 
		result.set_minus() ;
		return result; 
	}

	/// @brief calcul a ratio to the power n 
	/// @param r a ratio
	/// @param n exponent 
	/// @return the ratio to the power n
	constexpr static Ratio pow(const Ratio& r, const int n)
	noexcept{
		if(n==0) return Ratio<T>::one() ;
		Ratio<T> result = Ratio<T>(std::pow(r._numerator, n), std::pow(r._denominator, n)); 
		result.reduce() ;
		result.set_minus() ;	 
		return result; 
	}

	/// @brief calcul a ratio to the power n, its our fonction pow, not the best...
	/// @param r a ratio
	/// @param n exponent 
	/// @return the ratio to the power n
	constexpr static Ratio pow2(const Ratio& r, const int n)
	noexcept{
		assert( (n > 0 ) && "error: n is negativ. ");
		if(n==0) return Ratio<T>::one() ;
		Ratio<T> result = r; 
		for (size_t i = 0; i < n-1; i++){
			result = result*r ; 
		}
		result.reduce() ; 
		return result; 
	}

	/// @brief calcul the exponantial of a ratio
	/// @param r a ratio 
	/// @return a float corresponding to the the exponantial of the ratio
	constexpr static float exp(const Ratio& r)
	noexcept{
    	return std::pow(std::exp(r._numerator), 1.0/(float)(r._denominator));
	}

	/// @brief calcul the logarithm of a ratio
	/// @param r a ratio 
	/// @return a float corresponding to the the logarithm of the ratio
	constexpr static float log(const Ratio& r)
	noexcept{
		assert( (r._numerator > 0 || r._denominator > 0) && "error: log impossible under 1.");
   		return std::log(r._numerator) - std::log(r._denominator);
	}

	/// @brief calcul the square root of a ratio
	/// @param r a ratio
	/// @return a float corresponding to the square root of the ratio 
	constexpr static float sqrt(Ratio r)
	noexcept{
		assert( (r._numerator > 0 || r._denominator > 0) && "error: square root impossible under 1. ");
		return std::pow(r.convert_ratio_to_float(), 1.0/2.0);
	}

	/// @brief calcul the square root of a ratio
	/// @param r a ratio
	/// @return a float corresponding to the square root of the ratio 
	constexpr static float sqrt2(Ratio r)
	noexcept{
		assert( (r._numerator > 0 || r._denominator > 0) && "error: square root impossible under 1. ");
		return  std::sqrt(r._numerator) / std::sqrt(r._denominator); 
	}

	/// @brief nth root of a ratio
	/// @param r a ratio 
	/// @param n the n of n_th root
	/// @return a float corresponding to the n_th root of a ratio
	constexpr static float find_name(Ratio r, const int n) 
	noexcept{
		assert( (r._numerator > 0 || r._denominator > 0) && "error: find_name impossible under 1. ");
   		return std::pow(r.convert_ratio_to_float(), 1.0/(float)n);
	}

	/// @brief cos of a ratio function
	/// @param r ratio
	/// @return the cos of a ratio
	constexpr static float cos(Ratio& r)
	noexcept{
		return std::cos(r.convert_ratio_to_float()); 
	}

	/// @brief calculate the factorial of integer
	/// @return factorial of n	
	constexpr static int factorial(int n)
	noexcept{
		return n<=1 ? 1 : n*factorial(n-1);
	}

	/// @brief cos function by the taylor mathode
	/// @param r ratio
	/// @return the tcos of a ratio
	constexpr static float taylor_cos(const Ratio& r)
	noexcept{
		float result = 0.; 
		Ratio<T> r1(-1,1);
		int n = 16;
		for (int i = 0; i < n; i++){
			result = result + (pow(r1, i)*pow(r, 2*i)).convert_ratio_to_float()/factorial(2*i); 
		}
		return result;
	}

	



/*------------------- FRIENDS METHODES ---------------------*/

	/// \brief overload the operator << for ratio
    /// \param stream : input stream
    /// \param r : the ratio to output
    /// \return the output stream containing the ratio data
	friend std::ostream& operator<< (std::ostream& stream, const Ratio<T>& r) {			
		return (r._denominator == 0) ? stream << "inf" : stream << r._numerator << "/" << r._denominator ; 
	}; 

	/// @brief divide a number with a ratio
	/// @param nb number to divide to the ratio 
	/// @param r the ratio 
	/// @return a ratio corresponding to the division of the ratio and the number
	friend Ratio<T> operator/ (const int nb, const Ratio<T>& r){
		assert( (r._numerator != 0) && "error: the denominator is null");
		Ratio<T> result((r._denominator * nb), r._numerator);
		result.reduce() ; 
		result.set_minus() ; 
		return result; 
	}; 

	/// @brief multiply a rational and a int or a long int
	/// @param nb number to multiply to the ratio
	/// @param r ratio to multiply to the number
	/// @return a ratio corresponding to the multiplication of the ratio and the number
	friend Ratio<T> operator* (const int nb, const Ratio<T>& r){
		Ratio<T> result((r._numerator*nb),(r._denominator));
		result.reduce();
		result.set_minus() ; 
		return result;
	};

};	
