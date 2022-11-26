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
	Ratio abs(); 

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



/*------------------- FRIENDS METODES ---------------------*/

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
	return Ratio<T>(-this->_numerator, this->_denominator) ; 
}

template<typename T>
Ratio<T> Ratio<T>::operator+ (const Ratio& r)  {
	return Ratio<T>(this->_numerator*r._denominator+this->_denominator*r._numerator, this->_denominator*r._denominator) ; 
}

template<typename T>
Ratio<T> Ratio<T>::operator* (const Ratio<T>& r) {
	Ratio<T> result((this->_numerator*r._numerator), (this->_denominator*r._denominator)) ; 
	result.reduce() ; 
	return result; 
}


template<typename T>
Ratio<T> Ratio<T>::operator/(const Ratio<T>& r){
	return Ratio<T>((this->_numerator * r._denominator), (this->_denominator * r._numerator));
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

template<typename T>
Ratio<T> Ratio<T>::abs() {
	return Ratio<T>( std::abs(this->_numerator) , this->_denominator); 
}

template<typename T>
T Ratio<T>::convert_ratio_to_T(){
	return (T)((T)this->_numerator / (T)this->_denominator) ; 
}

template<typename T>
Ratio<T> Ratio<T>::inverse() {
	return Ratio<T>(this->_denominator, this->_numerator) ; 
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
	return Ratio<T>(Ratio<T>(q,1.0) + convert_float_to_ratio(x-q, nb_iter-1)); 
}
/*
template<typename T, typename U>
Ratio<T> Ratio<T>::pow(const Ratio<T>& r, const U n) {
	if(n==0) return one() ;
	Ratio<T> result = r * pow(r, std::abs(n-1));
	return (n<0) ? inverse(result) : result;
}*/

 


/*
    // constructor and default constructor
    Ratio(const size_t size=0, const T value = 0.0);

    // copy constructor
	Ratio(const Ratio &v) = default;
    
    // copy constructor other type 
    template<typename U>
	Ratio<T>(const Ratio<U> &vec) : Ratio<T>(vec.size()){
		for(size_t i=0; i<vec.size(); ++i)
			m_data[i] = static_cast<T>(vec[i]); 
	}

    // destructor
    ~Ratio() = default;

    // methods
    void display() const;
    T dot(const Ratio &v) const;
    inline T norm() const { return sqrt(this->dot(*this)); }
    inline size_t size() const { return m_data.size() ; }

    // operators
    Ratio& operator=(const Ratio &vec);
    Ratio operator+ (const Ratio& vec) ; 
    Ratio operator- (const Ratio& vec) ; 
    Ratio operator* (const Ratio& vec) ; 
    Ratio operator* (const int nb) ; 
    Ratio operator- () ; 

    const T& operator[](const size_t& i) const;
    T& operator[](const size_t& i);

    bool save(const std::string &filename) const;

};

template<typename T>
Ratio<T>::Ratio(const size_t size, const T value) 
: m_data(size,value) 
{}

template<typename T>
Ratio<T>& Ratio<T>::operator=(const Ratio<T> &vec)
{
	if(&vec == this) return *this;

	m_data = vec.m_data;

	return *this;
}

template<typename T>
Ratio<T> Ratio<T>::operator+ (const Ratio<T>& vec) {
	assert(m_data.size() == vec.size());

	Ratio v3(vec.size()) ;

	for(size_t i=0; i< vec.size(); ++i){
		v3[i] = m_data[i] + vec[i] ; 
	}
	return v3 ; 
}

template<typename T>
Ratio<T> Ratio<T>::operator- (const Ratio<T>& vec) {
	assert(m_data.size() == vec.size());

	Ratio v3(vec.size()) ;

	for(size_t i=0; i< vec.size(); ++i){
		v3[i] = m_data[i] - vec[i] ; 
	}
	return v3 ; 
}

template<typename T>
Ratio<T> Ratio<T>::operator- () {

	Ratio v3(m_data.size()) ;

	for(size_t i=0; i< m_data.size(); ++i){
		v3[i] = - m_data[i] ; 
	}
	return v3 ; 
}

template<typename T>
Ratio<T> Ratio<T>::operator* (const Ratio<T>& vec) {
	assert(m_data.size() == vec.size());

	Ratio v3(vec.size()) ;

	for(size_t i=0; i< vec.size(); ++i){
		v3[i] = m_data[i] * vec[i] ; 
	}
	return v3 ; 
}

template<typename T>
Ratio<T> Ratio<T>::operator* (const int nb) {

	Ratio v3(m_data.size()) ;

	for(size_t i=0; i< m_data.size(); ++i){
		v3[i] = m_data[i] * nb; 
	}
	return v3 ; 
}

template<typename T>
const T& Ratio<T>::operator[](const size_t& i) const{
    return m_data[i]; 
}

template<typename T>
T& Ratio<T>::operator[](const size_t& i){
    return m_data[i]; 
}

template<typename T>
void Ratio<T>::display() const {
	for(size_t i=0; i< m_data.size(); ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

template<typename T>
bool Ratio<T>::save(const std::string &filename) const{

	//open the file
	std::ofstream myfile;
	myfile.open(filename, std::ios::out | std::ios::binary);
	
	if(!myfile.is_open()){
		std::cerr << "error: can not create file: " << filename << std::endl;
		return false;
	}

	// write the vector size
	myfile << size() << std::endl;

	for(size_t i=0; i<size(); ++i)
		myfile << m_data[i] << " ";

	myfile.close();

	return true;
}

template<typename T>
T Ratio<T>::dot(const Ratio<T> & vec) const {
	assert(m_data.size() == vec.m_data.size());

	T result = 0.0;
	for(size_t i=0; i<m_data.size(); ++i)
		result += m_data[i] * vec.m_data[i];

	return result;
}

template<typename T>
std::ostream& operator<< (std::ostream& stream, const Ratio<T>& v) {
	for(size_t i=0; i< v.size(); ++i){
		stream << v[i] << " "; 
	}
	return stream ; 
}

template<typename T>
std::ostream& operator<< (std::ostream& stream, const Ratio<T>& v) ;

*/

