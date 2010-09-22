#ifndef LARGEINTEGER_H
#define LARGEINTEGER_H

#include <list>

class LargeInteger {
private:
	std::list<int> listInt;
	bool negativeFlag;

	std::string stripZeros(std::string number);
	std::list<int> stripZeros(std::list<int> number);


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
	std::list<int> value();
};



#endif/*LARGEINTEGER_H*/


