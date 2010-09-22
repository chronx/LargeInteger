#ifndef LARGEINTEGER_H
#define LARGEINTEGER_H

#include <list>

class LargeInteger {
private:
	std::list<int> listInt;
	bool negativeFlag;

	std::string stripZeros(std::string number);
	std::list<int> stripZeros(std::list<int> number);

	//std::list<int> sublist(std::list<int> number, int i, int j);

public:
	//Ctors
	LargeInteger() : negativeFlag(false) { listInt.push_back(0); }
	LargeInteger(std::list<int> list, bool negativeFlag) : listInt(list), negativeFlag(negativeFlag) { }
	LargeInteger(std::string numberStr) { value(numberStr); }
	LargeInteger(std::list<int>& number) { value(number); }


	LargeInteger add(std::list<int> number);
	LargeInteger add(LargeInteger number);

	LargeInteger multiply(LargeInteger number);
	LargeInteger multiply(std::list<int> number);

	//LargeInteger dacmultiply(LargeInteger number);
	//LargeInteger dacmultiply(std::list<int> number);

	LargeInteger subtract(std::list<int> number);
	LargeInteger subtract(LargeInteger number);

	//Operators
	LargeInteger& operator=(const LargeInteger& num);
	LargeInteger& operator=(const std::string& num);
	friend bool operator==(LargeInteger &i, LargeInteger &j);
	friend void operator -(LargeInteger &i);

	LargeInteger operator+(const LargeInteger& num);
	void operator+=(const LargeInteger& num);

	LargeInteger operator*(const LargeInteger& num);
	void operator*=(const LargeInteger& num);


	//Getters
	std::string LargeInteger::str();
	bool negative() { return negativeFlag; }
	//Setters
	void value(std::string numberStr);
	void value(std::list<int> number);
	void value(LargeInteger integer);
	void negative(bool negative) { negativeFlag = negative; }
	std::list<int> value();				// I don't like this but oh well
};



#endif/*LARGEINTEGER_H*/


/*

DaCMultiply( A[0..n-1], B[0..n-1]) {
	int n = sizeof(A); 	// sizeof(A) == sizeof(B) 
	if( n == 1) {		//sentinel size
		return (A[0] * B[0]) 
	} else {
		a_l <- A[0..floor(n/2)]
		a_r <- A[ceil(n/2)..n]
		b_l <- B[0..floor(n/2)]
		b_r <- B[ceil(n/2)..n]
		
		product1 <- DacMultiply( a_l, b_l )
		product2 <- DacMultiply( a_r, b_r )

		product3 <- DacMultiply( a_l, b_r )
		product4 <- DacMultiply( a_r, b_l )

		return (product1*10^(n/2) + (product3 + product4)*10^(n/2) + product2);

		//product3 <- DacMultiply( a_l + b_l, a_r + b_r)
		//return product1*10^n + (product3-product1-product2)*10^(n/2) + product2
		
	}
}
*/