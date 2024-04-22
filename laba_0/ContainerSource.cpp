#include "Container.h"
#include <vector>
#pragma once

	Container::Container(int length, int width, int height, double maxWeight)
	{
		this->length = length;
		this->width = width;
		this->height = height;
		this->maxWeight = maxWeight;
	}
	Container::Container() {
		this->length = 0;
		this->width = 0;
		this->height = 0;
		this->maxWeight = 0;
	}

	int boxCounter() {
		return vector.size();
	}

	double totalWeight(){
		double sumOfWeight = 0;
		for (int i = 0; i < vector.size(); i++) {
			sumOfWeight += vector[i].getWeight();
		}
		return sumOfWeight;
	}

	int totalCost(){
		double sumOfValue = 0;
		for (int i = 0; i < vector.size(); i++) {
			sumOfValue += vector[i].getValue();
		}
		return sumOfValue;
	}

	Box getBox(std::vector<Box> vector, int i) {
		return vector.at(i);
	}

	void addingABox(Box box) {
		std::vector<Box> vector;
		if (box.getWeight() + totalWeight() > this->maxWeight) {

		}
	}


