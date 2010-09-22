#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <list>

#include "LargeInteger.h"


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


	} catch(std::exception e) {
		std::cout<<"Exception: "<<e.what()<<std::endl;
	}

	std::cout<<"done"<<std::endl;
	system("pause");
	return 0;
}