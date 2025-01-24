#pragma once
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

class Wheel {
public:
	Wheel() {};
	Wheel(int slices) {
		wheelSize = slices;
	};
	void addToWheel(std::string text) {
		_input.push_back(text);
	}
	void assign(std::vector<std::string> things, int size) {
		for (int i = 0; i < size; i++) {
			_wheelspots.insert(std::make_pair(i, things[i]));
		}
	}
	void Spin() {
		assign(_input, wheelSize);
		rng = rand() % _wheelspots.size();
		std::cout << "SPINNING THE WHEEEEEEEEEEL" << std::endl;
		_results = _wheelspots.at(rng);
		std::cout << "Landed on: " + _results << std::endl;
	}

private:
	std::unordered_map<int, std::string> _wheelspots;
	std::vector<std::string> _input;
	std::string _results;
	int rng = 0;
	int wheelSize = 0;

};