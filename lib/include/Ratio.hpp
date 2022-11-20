#pragma once
#include <numeric>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cassert>


template<class T>
class Ratio {
private : 
	T _numerator ; 
    T _denominator;

public :

	// constructor and default constructor
    Ratio(const T _denominator=0, const T _numerator = 1.0);

    // copy constructor
	Ratio(const Ratio &r) = default;

    // destructor
    ~Ratio() = default;

	// methods
    void display() const;
	void reduce(); 
	void pow(const int n) ;


	 // operators
    Ratio& operator=(const Ratio &r);
    Ratio operator+ (const Ratio& r) ; 
    Ratio operator- (const Ratio& r) ; 
    Ratio operator* (const Ratio& r) ; 
    Ratio operator* (const int nb) ; 
    Ratio operator/ (const Ratio& r) ;
    Ratio operator- () ;  


	//friends function 
	friend Ratio<T> operator/(const Ratio<T>& r1, const Ratio<T>& r2);
	 Ratio zero(); 
	
	
	//friend Ratio<T> convert_float_to_ratio(const float x, const int nb_iter) const ; 


/*
	friend Ratio<T> Ratio<T> convert_float_to_ratio(const float x, const int nb_iter) const{
		if (x==0) return 0/1 ;
		if (nb_iter==0) return 0/1 ; 
		if(x<1){
			return 1/(convert_float_to_ratio(1/x, nb_iter)); 
		}
		int q = (int)x; 
		return q/1 + convert_float_to_ratio(x-q, nb_iter-1); 
	}; */
}; 

template<typename T>
Ratio<T> operator/(const Ratio<T>& r1, const Ratio<T>& r2){
	return Ratio<T>((r1._numerator * r2._denominator), (r1._denominator * r2._numerator));
}

template<typename T>
Ratio<T> Ratio<T>::zero(){
	Ratio<T> r(0.0,1.0) ;
	return r; 
}

template<typename T>
Ratio<T>::Ratio(const T num, const T den) 
: _numerator(num), _denominator(den)
{}

template<typename T>
void Ratio<T>::display() const {
	std::cout << _numerator << "/" << _denominator << std::endl;
}

template<typename T>
void Ratio<T>::pow(const int n) {
	if(n==0){	
		//*this = zero() ;
	}else if (n!=1 && n!=0){
		for (size_t i=2 ; i<=std::abs(n) ; i++){
			this->_numerator *= this->_numerator ; 
			this->_denominator *= this->_denominator ; 
		}
	}
	if (n<0){
		T num = this->_numerator; 
		this->_numerator = this->_denominator ; 
		this->_denominator = num ; 
	}
}

template<typename T>
void Ratio<T>::reduce() {
	T pgcd = std::gcd(this->_numerator, this->_denominator); 
	this->_numerator = this->_numerator/pgcd; 
	this->_denominator = this->_denominator/pgcd; 
}

template<typename T>
Ratio<T> Ratio<T>::operator* (const Ratio<T>& r) {
	return Ratio<T>((this->_numerator*r._numerator), this->_denominator*r._denominator) ; 
}


 


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

