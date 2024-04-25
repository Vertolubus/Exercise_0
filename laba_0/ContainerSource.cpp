#pragma once

#include<iostream>
#include "Container.h"
#include <vector>

namespace BoxAndContainer {
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

	int Container::boxCounter() const {
		return vector.size();
	}

	double Container::totalWeight() {
		double sumOfWeight = 0;
		for (int i = 0; i < vector.size(); i++) {
			sumOfWeight += vector[i].getWeight();
		}
		return sumOfWeight;
	}

	int Container::totalCost() {
		int sumOfValue = 0;
		for (int i = 0; i < vector.size(); i++) {
			sumOfValue += vector[i].getValue();
		}
		return sumOfValue;
	}

	Box Container::getBox(int i) const {
		return vector.at(i);
	}

	int Container::addingABox(Box& box) {
		if (box.getWeight() + totalWeight() > this->maxWeight) {
			throw std::exception("����� ������� ����������� ������������ ���������������� ����������");
		}
		else {
			vector.push_back(box);
			return boxCounter();
		}
	}

	void Container::deleteBox(int i) {
		vector.erase(vector.begin() + i);
	}

	std::istream& operator>>(std::istream& in, Container& container)
	{
		Box box;
		int length, width, height;
		double maxWeight;
		int n;

		in >> length >> width >> height >> maxWeight;

		container = Container(length, width, height, maxWeight);
		in >> n;

		for (int i = 0; i < n; i++) {
			in >> box;
			try {
				container.addingABox(box);
			}
			catch (std::exception) {
				std::cout << "����� ������� ������� �� ������� ���������� ����������������!!!" << std::endl;
				break;
			}
		}
		return in;
	}


	std::ostream& operator<<(std::ostream& out, const Container& container)
	{
		out << "�����: " << container.getLength() << "; ������: " << container.getWidth() << "; ������: " << container.getHeight() << "; ����������� ���������� ���: " << container.getMaxWeight() << std::endl;
		for (int i = 0; i < container.boxCounter(); i++) {
			out << "������� # " << i + 1 << ":  " << container.getBox(i) << std::endl;
		}
		return out;
	}

	Box& Container::operator[](const int i) {
		return this->vector[i];
	}
}