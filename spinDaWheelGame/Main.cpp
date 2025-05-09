#include <iostream>
#include <limits>
#include "Wheel.h"

//todo: have ui be entirely in class, animated wheel??
int main() {
	int size;
	std::string input;
	std::cout << "Enter wheel size: ";
	std::cin >> size;
	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
	Wheel wheel1(size);

	return 0;
}