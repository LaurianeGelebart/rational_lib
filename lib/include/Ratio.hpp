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

	/// @brief reduce the ratio to its irreducible form
	void reduce(); 

	/// @brief if the ratio is negative, put the sign on the numerator
	void set_minus(); 

	/// @brief find the absolute value of a ratio 
    /// @return the absolute value the calling ratio 
	constexpr Ratio abs() 
	noexcept{
		return Ratio<T>( std::abs(this->_numerator) , this->_denominator); 
	}

/* -----Lequel est le mieux ?-------
template<typename T>
Ratio<T> Ratio<T>::abs() {
	return (this->_numerator < static_cast<T>(0)) ? Ratio<T>( -this->_numerator , this->_denominator) : Ratio<T>(this->_numerator, this->_denominator) ;	
}*/


	/// @brief convert a ratio to a float rumber 
	/// @return the ratio converted into a float
	float convert_ratio_to_float();

	/// @brief inverse a ratio 
	/// @return the inverted ratio 
	Ratio inverse() ; 


/*------------------- STATIC METHODES ---------------------*/

	/// @brief the zero-valued rational
	/// @return 0.0/1.0
	static Ratio zero(); 

	/// @brief the rational corresponding to the value one
	/// @return 1.0/1.0
	static Ratio one(); 

	/// @brief the rational correspondind to infinity
	/// @return 1.0/0.0
	static Ratio inf(); 

	/// @brief convert a real number to a Ratio
	/// @param x the real to convert to ratio 
	/// @param nb_iter number of recursive call 
	/// @return  the real converted into a rational 
	static Ratio convert_float_to_ratio(const float x, const int nb_iter) ;  

	/// @brief calcul a ratio to the power n 
	/// @param r a ratio
	/// @param n exponent 
	/// @return the ratio to the power n
	static Ratio pow(const Ratio& r, const int n); 

	/// @brief calcul the exponantial of a ratio
	/// @param r a ratio 
	/// @return a float corresponding to the the exponantial of the ratio
	static float exp(const Ratio& r); 

	/// @brief calcul the logarithm of a ratio
	/// @param r a ratio 
	/// @return a float corresponding to the the logarithm of the ratio
	static float log(const Ratio& r);

	/// @brief calcul the square root of a ratio
	/// @param r a ratio
	/// @return a float corresponding to the square root of the ratio 
	static float sqrt(Ratio r);

	/// @brief 
	/// @param r a ratio 
	/// @param n 
	/// @return 
	static float find_name(Ratio r, const int n) ; 


	static float cos(const Ratio& r); // A faire 


	



/*------------------- FRIENDS METHODES ---------------------*/

	/// \brief overload the operator << for ratio
    /// \param stream : input stream
    /// \param r : the ratio to output
    /// \return the output stream containing the ratio data
	friend std::ostream& operator<< (std::ostream& stream, const Ratio<T>& r) {			
		return (r._denominator == 0) ? stream << "inf" : stream << r._numerator << "/" << r._denominator ; 
	}; 

};	


//--------------------------Constructor------------------------------//
template<typename T>
Ratio<T>::Ratio(const T num, const T den) {
	 static_assert(std::is_integral<T>::value, "Integral required.");
	 //assert( (this->_denominator != 0) && "error: the denominator can't be null");
	 this->_numerator = num ; 
	 this->_denominator = den ; 
}

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
Ratio<T> Ratio<T>::operator- (const Ratio& r)  {
	Ratio<T> result(this->_numerator*r._denominator-this->_denominator*r._numerator, this->_denominator*r._denominator); 
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
	if (this->_denominator == 0)  std::cout << "inf" << std::endl ; 
	else std::cout << this->_denominator << "/" << this->_denominator << std::endl;
}


template<typename T>
void Ratio<T>::reduce() {
	T pgcd = std::gcd(this->_numerator, this->_denominator); 
	this->_numerator = this->_numerator/pgcd; 
	this->_denominator = this->_denominator/pgcd; 
}

template<typename T> 
void Ratio<T>::set_minus(){
	if((this->_numerator() > 0 && this->_denominator() < 0 )
	|| (this->_numerator() < 0 && this->_denominator() < 0 ) ){
		this->_numerator = -this->_numerator ; 
		this->_denominator = -this->_denominator ; 
	}
}

template<typename T>
float Ratio<T>::convert_ratio_to_float(){
	return (float)((float)this->_numerator / (float)this->_denominator) ; 
}

template<typename T>
Ratio<T> Ratio<T>::inverse() {
	assert( (this->_denominator != 0) && "error: the denominator is null, impossible to inverse inf");
	assert( (this->_numerator != 0) && "error: the numerator is null, impossible to inverse this ratio");
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
	if (x<0){
        return -(convert_float_to_ratio(-x,nb_iter));
    }
	if(x<1){
		return Ratio<T>(1.0,(convert_float_to_ratio((float)1.0/x, nb_iter).convert_ratio_to_float())); 
	}
	float q = (int)x; 
	Ratio<T> result(Ratio<T>(q,1.0) + convert_float_to_ratio(x-q, nb_iter-1)); 
	result.reduce() ; 
	return result; 
}

//------- souvenir de pow sans std pour le rapport ----------//
/*template<typename T>
Ratio<T> Ratio<T>::pow(const Ratio<T>& r, const int n) {
	if(n==0) return Ratio<T>::one() ;
	Ratio<T> result = r;
	for (size_t i = 0; i <  std::abs(n-1); i++){
		result = result*r ; 
	}
	result.reduce() ; 
	if (n<0) result = result.inverse();
	return result; 
}*/

template<typename T>
Ratio<T> Ratio<T>::pow(const Ratio<T>& r, const int n) {
	if(n==0) return Ratio<T>::one() ;
	Ratio<T> result = Ratio<T>(std::pow(r._numerator, n), std::pow(r._denominator, n)); 
	result.reduce() ; 
	return result; 
}

template<typename T>
float Ratio<T>::exp(const Ratio<T>& r){
    return std::pow(std::exp(r._numerator), 1.0/(float)(r._denominator));
}

template<typename T>
float Ratio<T>::find_name(Ratio<T> r, const int n){
	assert( (r._numerator > 0 || r._denominator > 0) && "error: find_name impossible under 1. ");
    return std::pow(r.convert_ratio_to_float(), 1.0/(float)n);
}

template<typename T>
float Ratio<T>::sqrt(Ratio<T> r){
	assert( (r._numerator > 0 || r._denominator > 0) && "error: square root impossible under 1. ");
    return std::pow(r.convert_ratio_to_float(), 1.0/(float)2);
   // return  std::sqrt(r._numerator) / std::sqrt(r._denominator); C'est quoi le mieux ?
}

template<typename T>
float Ratio<T>::log(const Ratio<T> &r){
	assert( (r._numerator > 0 || r._denominator > 0) && "error: log impossible under 1.");
    return std::log(r._numerator) - std::log(r._denominator);
}

