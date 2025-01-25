#pragma once
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<chrono>
#include<thread>

class Wheel {
public:
	Wheel() {};
	Wheel(int size) {
		_wheelSize = size;
		for (int i = 0; i < _wheelSize; i++) {
			std::cout << "Enter Segment Text: ";
			std::cin >> _segment;
			addToWheel(_segment);
		}
		Spin();
	}
	void addToWheel(std::string text) {
		_input.push_back(text);
	}
	void assign(std::vector<std::string> things, int size) {
		for (int i = 0; i < size; i++) {
			_wheelspots.insert(std::make_pair(i, things[i]));
		}
	}
	void Spin() {
		assign(_input, _wheelSize);
		_rng = rand() % _wheelspots.size();
		std::cout << "IT'S TIME TO SPIN THE WHEEL" << std::endl;
		std::cout << "Spinning......";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cout << std::endl;
		_results = _wheelspots.at(_rng);
		std::cout << "Landed on: " + _results << std::endl;
	}

private:
	std::unordered_map<int, std::string> _wheelspots;
	std::vector<std::string> _input;
	std::string _results;
	int _rng;
	int _wheelSize;
	std::string _segment;

};