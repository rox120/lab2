#include <iostream>
#include "calculator.h"

int main() {
	int a = 10;
	int b = 5;

	std::cout << "Add: " << add(a, b) << std::endl;
	std::cout << "Subtract: " << subtract(a, b) << std::endl;
	std::cout << "Multiply: " << multiply(a, b) << std::endl;

	try {
		std::cout << "Divide: " << divide(a, b) << std::endl;
	} catch (const char* msg) {
		std::cerr << msg << std::endl;
	}

	return 0;
}
