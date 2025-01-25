#include <iostream>
#include "Wheel.h"
#include <chrono>
//todo: have ui be entirely in class, animated wheel??
int main() {
	int size;
	std::string input;
	std::cout << "Enter wheel size: ";
	std::cin >> size;
	Wheel wheel1(size);

	return 0;
}
