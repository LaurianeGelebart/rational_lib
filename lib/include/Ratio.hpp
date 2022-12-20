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
    Ratio(const T _numerator=0.0, const T _denominator = 1.0);

	/// @brief copy-constructor
	/// @param r source ratio to be copied
	Ratio(const Ratio &r) = default;

    /// @brief destructor
    ~Ratio() = default;


/*------------------- GETTERS ---------------------*/
	
	/// @brief getter of the ratio numerator 
	/// @return numerator of the current ratio
	T get_numerator(); 
	
	/// @brief getter of the ratio denominator 
	/// @return denominator of the current ratio
	T get_denominator(); 

	/// @brief 
	/// @param num 
	void set_numerator(T num) ; 

	/// @brief 
	/// @param den 
	void set_denominator(T den) ; 


/*------------------- OPERATOR ---------------------*/

    /// @brief affectation operator
    /// @param r ratio affetct to the calling ratio 
    Ratio& operator=(const Ratio &r);

	/// @brief add 2 ratio of the same type
    /// @param r ratio to add to the calling ratio 
    /// @return the sum of the current ratio and the argument ratio
    Ratio operator+ (const Ratio& r) ; 

    Ratio operator- (const Ratio& r) ; 

    /// @brief multiply 2 ratio of the same type
    /// @param r ratio to multiply to the calling ratio 
    /// @return the multiplication of the current ratio and the argument ratio
    Ratio operator* (const Ratio& r) ; 

    /// @brief multiply a rational and a int
    /// @param nb int to multiply to the calling ratio
    /// @return the multiplication of the current ratio and the argument int
    Ratio operator* (const int nb) ; 

    /// @brief divide 2 ratio of the same type
    /// @param r ratio to divide to the calling ratio 
    /// @return the division of the current ratio and the argument ratio
	Ratio operator/ (const Ratio& r) ;

    /// @brief unary minus
    /// @return the minus the calling ratio 
    Ratio operator- () ;  

    bool operator== (const Ratio& r) ;
    bool operator!= (const Ratio& r) ;
    bool operator<= (const Ratio& r) ;
    bool operator>= (const Ratio& r) ;
    bool operator< (const Ratio& r) ;
    bool operator> (const Ratio& r) ;



/*------------------- METHODES ---------------------*/

	/// @brief display the ratio
    void display() const;

	/// @brief reduce a ratio to its irreducible form
	void reduce(); 

	/// @brief find the absolute value of a ratio 
    /// @return the absolute value the calling ratio 
	constexpr Ratio abs() 
	noexcept{
		return (this->_numerator < static_cast<T>(0)) ? Ratio<T>( -this->_numerator , this->_denominator) : Ratio<T>(this->_numerator, this->_denominator) ;
	}

	/// @brief convert a ratio to a real rumber 
	/// @return the ratio converted into a real
	T convert_ratio_to_T();

	/// @brief inverse a ratio 
	/// @return the inverted ratio 
	Ratio inverse() ; 


/*------------------- STATIC METHODES ---------------------*/

	/// @brief the zero-valued rational
	/// @return 0.0/1.0
	static Ratio zero(); 

	/// @brief the rational of one
	/// @return 1.0/1.0
	static Ratio one(); 

	/// @brief the rational of infinity
	/// @return 1.0/0.0
	static Ratio inf(); 

	/// @brief convert a real number to a Ratio
	/// @param x the real to convert to ratio 
	/// @param nb_iter number of recursive call 
	/// @return  the real converted into a rational 
	static Ratio convert_float_to_ratio(const float x, const int nb_iter) ;  

	// c'est en cours pas touche 
	static Ratio pow(const Ratio& r, const int n); 



/*------------------- FRIENDS METHODES ---------------------*/

	/// \brief overload the operator << for ratio
    /// \param stream : input stream
    /// \param r : the ratio to output
    /// \return the output stream containing the ratio data
	friend std::ostream& operator<< (std::ostream& stream, const Ratio<T>& r) {			
		stream << r._numerator << "/" << r._denominator ;
		return stream;
	}; 

};	


//--------------------------Constructor------------------------------//
template<typename T>
Ratio<T>::Ratio(const T num, const T den) 
: _numerator(num), _denominator(den)
{}

//--------------------------Getters------------------------------//

template<typename T>
T Ratio<T>::get_numerator(){
	return this->_numerator ; 
}

template<typename T>
T Ratio<T>::get_denominator(){
	return this->_denominator ; 
}

template<typename T>
void Ratio<T>::set_numerator(T num){
	this->_numerator = num ; 
}

template<typename T>
void Ratio<T>::set_denominator(T den){
	this->_denominator = den; 
}

//--------------------------Operator------------------------------//
template<typename T>
Ratio<T>& Ratio<T>::operator=(const Ratio<T> &r)
{
	if(&r == this) return *this;

	this->_denominator = r._denominator;
	this->_numerator = r._numerator;

	return *this;
}

template<typename T>
Ratio<T> Ratio<T>::operator- () {
	Ratio<T> result(-this->_numerator, this->_denominator) ; 
	result.reduce() ; 
	return result; 
}

template<typename T>
Ratio<T> Ratio<T>::operator+ (const Ratio& r)  {
	Ratio<T> result(this->_numerator*r._denominator+this->_denominator*r._numerator, this->_denominator*r._denominator); 
	result.reduce() ; 
	return result; 
}

template<typename T>
Ratio<T> Ratio<T>::operator* (const Ratio<T>& r) {
	Ratio<T> result((this->_numerator*r._numerator), (this->_denominator*r._denominator)) ; 
	result.reduce() ; 
	return result; 
}

//Faire Test unitaire
template<typename T>
Ratio<T> Ratio<T>::operator* (const int nb){
	Ratio<T> result((this->_numerator*nb),(this->_denominator));
	result.reduce();
	return result;

}





template<typename T>
Ratio<T> Ratio<T>::operator/(const Ratio<T>& r){
	Ratio<T> result((this->_numerator * r._denominator), (this->_denominator * r._numerator));
	result.reduce() ; 
	return result; 
}

//Faire test unitaire
template<typename T>
bool Ratio<T>::operator== (const Ratio& r){
	return this->_numerator == r._numerator && this->_denominator == r._denominator ? true : false;
}

//Faire Test unitaire
template<typename T>
bool Ratio<T>::operator!= (const Ratio& r){
	return this->_numerator != r._numerator && this->_denominator != r._denominator ? true : false;
}

//Faire Test unitaire
template<typename T>
bool Ratio<T>::operator<= (const Ratio& r){
	return this->_numerator <= r._numerator && this->_denominator <= r._denominator ? true : false;
	
}

//Faire Test unitaire
template<typename T>
bool Ratio<T>::operator>= (const Ratio& r){
	return this->_numerator >= r._numerator && this->_denominator >= r._denominator ? true : false;
}

//Faire Test Unitaire
template<typename T>
bool Ratio<T>::operator< (const Ratio& r){
	return this->_numerator < r._numerator && this->_denominator < r._denominator ? true : false;
}

//Faire Test Unitaire
template<typename T>
bool Ratio<T>::operator> (const Ratio& r){
	return this->_numerator > r._numerator && this->_denominator > r._denominator ? true : false;
}




//--------------------------Methodes------------------------------//
template<typename T>
void Ratio<T>::display() const {
	std::cout << _numerator << "/" << _denominator << std::endl;
}


template<typename T>
void Ratio<T>::reduce() {
	T pgcd = std::gcd(this->_numerator, this->_denominator); 
	this->_numerator = this->_numerator/pgcd; 
	this->_denominator = this->_denominator/pgcd; 
}

/* -----Lequel est le mieux ?-------
template<typename T>
Ratio<T> Ratio<T>::abs() {
	return Ratio<T>( std::abs(this->_numerator) , this->_denominator); 
}*/


template<typename T>
T Ratio<T>::convert_ratio_to_T(){
	return (T)((T)this->_numerator / (T)this->_denominator) ; 
}

template<typename T>
Ratio<T> Ratio<T>::inverse() {
	Ratio<T> result (this->_denominator, this->_numerator) ; 
	result.reduce() ; 
	return result; 
}



//--------------------------static------------------------------//
template<typename T>
Ratio<T> Ratio<T>::zero(){
	return Ratio<T>(0.0,1.0); 
}

template<typename T>
Ratio<T> Ratio<T>::one(){
	return Ratio<T>(1.0,1.0); 
}

template<typename T>
Ratio<T> Ratio<T>::inf(){
	return Ratio<T>(1.0,0.0); 
}

template<typename T>
Ratio<T> Ratio<T>::convert_float_to_ratio(const float x, const int nb_iter){
	if (x==0 || nb_iter==0) return zero() ;
	if(x<1){
		return Ratio<T>(1.0,(convert_float_to_ratio((float)1.0/x, nb_iter).convert_ratio_to_T())); 
	}
	float q = (int)x; 
	Ratio<T> result(Ratio<T>(q,1.0) + convert_float_to_ratio(x-q, nb_iter-1)); 
	result.reduce() ; 
	return result; 
}

/*
template<typename T, typename U>
Ratio<T> Ratio<T>::pow(const Ratio<T>& r, const U n) {
	if(n==0) return one() ;
	Ratio<T> result = r * pow(r, std::abs(n-1));
	return (n<0) ? inverse(result) : result;
}*/

 
