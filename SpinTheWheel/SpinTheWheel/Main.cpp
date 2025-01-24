#include <iostream>
#include "Wheel.h"

//todo: add delay to spin, have ui be entirely in class, animated wheel??
int main() {
	int size;
	std::string input;
	std::cout << "Enter wheel size: ";
	std::cin >> size;
	Wheel wheel1(size);
	for (int i = 0; i < size; i++) {
		input = "";
		std::cout << "Enter segment text: ";
		std::cin >> input;
		wheel1.addToWheel(input);
	}
	/*wheel1.addToWheel("text1");
	wheel1.addToWheel("text2");*/
	wheel1.Spin();
	return 0;
}