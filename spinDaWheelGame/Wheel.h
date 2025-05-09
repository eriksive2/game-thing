#pragma once
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<chrono>
#include<thread>
#include<random>

class Wheel {
public:

	//constructors
	Wheel() {};
	Wheel(int size) {
		_wheelSize = size;
		//input for segments
		for (int i = 0; i < _wheelSize; i++) {
			std::cout << "Enter Segment Text:" ;
			std::getline(std::cin, _segment);
			addToWheel(_segment);
		}
		Spin();
	}

	//adds inputs to wheel vectors
	void addToWheel(std::string text) {
		_input.push_back(text);
	}

	//assigns ints to each vector part so rng can pick a segment
	void assign(std::vector<std::string> things, int size) {
		for (int i = 0; i < size; i++) {
			_wheelspots.insert(std::make_pair(i, things[i]));
		}
	}

	//picks a random number from a range using mersenne twist engine returns the random int
	int random(int endRange){
		std::random_device rand;
		std::mt19937 gen(rand());
		std::uniform_int_distribution<> distrib(1, _wheelSize);
		
		return distrib(gen);
	}

	//gives each segment an int, waits for 3 seconds, then displays results of rng
	void Spin() {
		assign(_input, _wheelSize);		
		std::cout << "IT'S TIME TO SPIN THE WHEEL" << std::endl;
		std::cout << "Spinning......";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cout << std::endl;
		_results = _wheelspots.at(random(_wheelSize));
		std::cout << "Landed on: " + _results << std::endl;
	}

private:
	std::unordered_map<int, std::string> _wheelspots;
	std::vector<std::string> _input;
	std::string _results;
	int _wheelSize;
	std::string _segment;

};