#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <list>

#include "LargeInteger.h"

std::list<int> sublist(std::list<int> number, int i, int j) {
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
}


//This is broken and causes stack overflows at current, because n >= 2 always, needs to be fixed.
LargeInteger dacmultiply(std::list<int> listInt, std::list<int> number) {

	int n = number.size();
	std::cout<<"DACMULTIPLY size="<<n<<std::endl;
	if(n == 1) {
		std::list<int>::iterator i,j;
		i = listInt.begin();
		j = number.begin();
		std::stringstream o;
		o<<((*i)*(*j));
		return LargeInteger(o.str());
	} else {
		std::list<int> al, ar, bl, br;

		al = sublist(listInt,0,floor((float)(n/2)));
		ar = sublist(listInt,ceil((float)n/2),n);
		bl = sublist(number,0,floor((float)(n/2)));
		br = sublist(number,ceil((float)n/2),n);

		LargeInteger p1,p2,p3,p4;
		p1 = dacmultiply(al, bl);
		p2 = dacmultiply(ar, br);
		p3 = dacmultiply(al, br);
		p4 = dacmultiply(ar, bl);

		LargeInteger p5;
		p5 = p3 + p4;

		int f = (int)(n/2);
		int c = (int)(n/2+1);
		for(int i = 0; i < f; i++) {
			std::list<int> temp = p1.value();
			temp.push_back(0);
			p1.value(temp);
		}
		for(int i = 0; i < f; i++) {
			std::list<int> temp = p5.value();
			temp.push_back(0);
			p5.value(temp);
		}

		return (p1 + p5 + p2);
	}
}


int main() {
	//Hello github!
	try {
		LargeInteger i,j;

		i = "9999";
		j = "1111";

		LargeInteger sum = i.add(j);
		std::cout<<"sum = "<<sum.str()<<std::endl;

		LargeInteger product = i.multiply(j);
		std::cout<<"product = "<<product.str()<<std::endl;


		LargeInteger dac;
		dac = dacmultiply(i.value(), j.value());


	} catch(std::exception e) {
		std::cout<<"Exception: "<<e.what()<<std::endl;
	}

	std::cout<<"done"<<std::endl;
	system("pause");
	return 0;
}