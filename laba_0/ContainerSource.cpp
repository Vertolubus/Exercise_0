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

	int Container::boxCounter() {
		return vector.size();
	}

	double Container::totalWeight(){
		double sumOfWeight = 0;
		for (int i = 0; i < vector.size(); i++) {
			sumOfWeight += vector[i].getWeight();
		}
		return sumOfWeight;
	}

	int Container::totalCost(){
		double sumOfValue = 0;
		for (int i = 0; i < vector.size(); i++) {
			sumOfValue += vector[i].getValue();
		}
		return sumOfValue;
	}

	Box Container::getBox(int i) {
		return vector.at(i);
	}

	int Container::addingABox(Box box) {
		std::vector<Box> vector;
		if (box.getWeight() + totalWeight() > this->maxWeight) {
			throw std::exception("Масса коробок превосходит максимальную грузоподъемность контейнера");
		}
		else {
			vector.push_back(box);
			return boxCounter();
		}
	}

	void Container::deleteBox(int i) {
		auto iter = vector.cbegin();
		vector.erase(iter + i);
	}

