#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include "LargeInteger.h"


LargeInteger LargeInteger::add(std::list<int> number)
{
	int sizeOne = listInt.size(); //vecInt - local
	int sizeTwo = number.size();  //number - remote
	//Pad numbers properly
	if(sizeOne > sizeTwo) {
		for(int i = 0; i < sizeOne - sizeTwo; i++)
			number.push_front(0);
	} else if(sizeOne < sizeTwo) {
		for(int i = 0; i < sizeTwo - sizeOne; i++)
			listInt.push_front(0);
	}
	sizeOne = listInt.size();
	sizeTwo = number.size();

	int carry = 0;
	std::list<int> sum;
	std::list<int>::reverse_iterator i = listInt.rbegin();
	std::list<int>::reverse_iterator j = number.rbegin();

	//std::cout<<"Adding..."<<std::endl;
	for(i; i != listInt.rend(); i++) {
	//	std::cout<<"adding "<<*i<<" and "<<*j<<" and carry ("<<carry<<")";
		int n = *i + *j + carry;
	//	std::cout<<" = "<<n<<std::endl;
		carry = 0;
		if( n >= 10 ) {
			carry = (int)(n/10);//(n - (n%10))/10;
			n = n % 10;
	//		std::cout<<"\tcarry="<<carry<<" n="<<n<<std::endl;
		}
		
		sum.push_front(n);
		j++;		
	}
	if(carry>0)
		sum.push_front(carry);

	return LargeInteger(sum,false);	
}


LargeInteger LargeInteger::subtract(std::list<int> number) {
	int sizeOne = listInt.size(); //vecInt - local
	int sizeTwo = number.size(); //number - remote
	//Pad numbers properly
	if(sizeOne > sizeTwo) {
		for(int i = 0; i < sizeOne - sizeTwo; i++)
			number.push_front(0);
	} else if(sizeOne < sizeTwo) {
		for(int i = 0; i < sizeTwo - sizeOne; i++)
			listInt.push_front(0);
	}
	sizeOne = listInt.size();
	sizeTwo = number.size();

	std::list<int> difference;

	return difference;
}


LargeInteger LargeInteger::multiply(std::list<int> number) {
	/*int sizeOne = listInt.size(); //vecInt - local
	int sizeTwo = number.size(); //number - remote
	//Pad numbers properly
	if(sizeOne > sizeTwo) {
		for(int i = 0; i < sizeOne - sizeTwo; i++)
			number.push_front(0);
	} else if(sizeOne < sizeTwo) {
		for(int i = 0; i < sizeTwo - sizeOne; i++)
			listInt.push_front(0);
	}
	sizeOne = listInt.size();
	sizeTwo = number.size();*/

	int factor = 0;
	int carry = 0;
	std::vector<std::list<int>> rows;
	std::list<int>::reverse_iterator i = listInt.rbegin(); 
	std::list<int>::reverse_iterator j = number.rbegin();

	std::cout<<"Multiplying... ";
//	system("pause");
	for( j; j != number.rend(); j++) {
		std::list<int> row;
		for( i = listInt.rbegin(); i != listInt.rend(); i++) {
			int n = (*i) * (*j) + carry;
	//		std::cout<<"multiplying "<<*i<<" by "<<*j<<" + carry ("<<carry<<") = "<<n<<std::endl;
			carry = 0;
			if(n >= 10) {
				carry = (int)(n/10);
				n = n % 10;
	//			std::cout<<"carry = "<<carry<<" n = "<<n<<std::endl;
			}
			row.push_front(n);
			
		}
		if(carry>0)
				row.push_front(carry);
		for(int f = 0; f < factor; f++)
			row.push_back(0);
		factor++;
		rows.push_back(row);		
	}

	std::cout<<"Combining products..."<<std::endl; factor--;
//	system("pause");
	LargeInteger product;
	std::vector<std::list<int>>::iterator iter;
	for(iter = rows.begin(); iter != rows.end(); iter++) {
		LargeInteger temp(*iter,false);
		for(int z = 0; z < factor; z++)
			std::cout<<" ";
		factor--;
		std::cout<<temp.str()<<std::endl;
		product = product.add(*iter);
	}
	return product;
}










LargeInteger LargeInteger::add(LargeInteger number) {
	return add(number.value());
}

LargeInteger LargeInteger::subtract(LargeInteger number) {
	return subtract(number.value());
}

LargeInteger LargeInteger::multiply(LargeInteger number) {
	return multiply(number.value());
}

/*LargeInteger LargeInteger::dacmultiply(LargeInteger number) {
	return dacmultiply(number.value());
}*/

// 
// Operators
//

LargeInteger& LargeInteger::operator = (const LargeInteger& num) {
	if(this != &num) {
		listInt = num.listInt;
		negativeFlag = num.negativeFlag;
	}
	return *this;
}

LargeInteger& LargeInteger::operator = (const std::string& num) {
	this->value(num);
	return *this;
}

bool operator==(LargeInteger &i, LargeInteger &j) {
	return (i.value() == j.value() &&
			i.negativeFlag == j.negativeFlag);
}
void operator - (LargeInteger &i) {
	i.negative(true);
}

LargeInteger LargeInteger::operator + (const LargeInteger& num) {
	LargeInteger temp(*this);
	temp = temp.add(num.listInt);
	return temp;
}

void LargeInteger::operator += (const LargeInteger& num) {
	*this = this->add(num.listInt);
}

LargeInteger LargeInteger::operator * (const LargeInteger& num) {
	LargeInteger temp(*this);
	temp = temp.multiply(num.listInt);
	return temp;
}

void LargeInteger::operator *= (const LargeInteger& num) {
	*this = this->multiply(num.listInt);
}

// 
// Utility
//

std::string LargeInteger::stripZeros(std::string number) {
	int size = number.length();
	int i = 0;
	for( i; i < size; i++)
		if(number[i]!='0') 
			break;
	return number.substr(i);
}

std::list<int> LargeInteger::stripZeros(std::list<int> number) {
	std::cout<<"number.size() = "<<number.size()<<std::endl;
	std::list<int> temp;
	int size = number.size();
	int i = 0;
	std::list<int>::iterator iter;
	for(iter = number.begin(); iter != number.end(); iter++) {
		std::cout<<"i = "<<i<<std::endl;
		if(*iter != 0)
			break;
		i++;
	}
	for(iter; iter != number.end(); iter++) {
		int n = *iter;
		std::cout<<"Adding "<<n<<std::endl;
		temp.push_back(n);
	}
	std::cout<<"returning..."<<std::endl;
	return temp;
}

/*std::list<int> LargeInteger::sublist(std::list<int> number, int i, int j) {
	int x = 0;
	int y = 0;
	std::list<int> newList;
	std::list<int>::iterator iter = number.begin();
	for(iter; iter != number.end(); iter++) {
		if(x==i)
			break;
		x++;
		y++;
	}
	for(iter; iter != number.end(); iter++) {
		newList.push_back(*iter);
		if(y==j)
			break;
		y++;
	}
	return newList;
}*/


//Getter
std::string LargeInteger::str() {
	std::ostringstream o;
	if(negativeFlag==true)
		o<<"-";
	std::list<int>::iterator i;
	for(i = listInt.begin(); i != listInt.end(); i++) {
		o<<*i;
	}

	return o.str();
}

//Setters
void LargeInteger::value(LargeInteger integer) {
	listInt = integer.listInt;
	negativeFlag = integer.negativeFlag;
}

void LargeInteger::value(std::list<int> number) {
	listInt = number;
}

void LargeInteger::value(std::string numberStr) {
	int size = strlen(numberStr.c_str());
	const char *cstr = numberStr.c_str();
	int start = 0;
	if(cstr[0]=='-') {
		negativeFlag = true;
		start++;
	}

	listInt.clear();

	std::cout<<"value(): ";
	for(int i = start; i < size; i++) {
		const char c = cstr[i];
		listInt.push_back(atoi( &c ));
		std::cout<<cstr[i];
	}
	std::cout<<std::endl;
}


std::list<int> LargeInteger::value() {
	return listInt;

}	
