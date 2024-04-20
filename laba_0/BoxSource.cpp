#pragma once

#include <iostream>
#include "Box.h"

	Box::Box(int length, int width, int height, double weight, int value)
	{
		this->length = length;
		this->width = width;
		this->height = height;
		this->weight = weight;
		this->value = value;
	}
	Box::Box()
	{
		this->length = 0;
		this->width = 0;
		this->height = 0;
		this->weight = 0;
		this->value = 0;
	}


int sumValue(Box box[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res += box[i].getValue();
	}
	return res;
}

bool lessThanTheSpecifiedValue(Box box[], int n, int maxValue)
{
	int sumOfAllValues = 0;
	for (int i = 0; i < n; i++)
	{
		sumOfAllValues += box[i].getLength();
		sumOfAllValues += box[i].getWidth();
		sumOfAllValues += box[i].getHeight();
		if (sumOfAllValues > maxValue)
		{
			return false;
		}
	}

	return true;
}

double volumCheck(Box box[], int n, int maxV)
{
	double maxWeight = 0;

	for (int i = 0; i < n; i++)
	{
		if (box[i].getLength() * box[i].getWidth() * box[i].getHeight() <= maxV)
		{
			if (box[i].getWeight() > maxWeight) maxWeight = box[i].getWeight();
		}
	}
	return maxWeight;
}

bool matryoshka(Box box[], int n)
{
	Box temp;
	Box* copyBox = new Box[n];

	for (int i = 0; i < n; i++)
	{
		copyBox[i] = box[i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (copyBox[j].getLength() > copyBox[j + 1].getLength())
			{
				temp = copyBox[j];
				copyBox[j] = copyBox[j + 1];
				copyBox[j + 1] = temp;
			}
			else if (copyBox[j].getLength() == copyBox[j + 1].getLength()) {
				return false;
			}
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (copyBox[i].getHeight() >= copyBox[i + 1].getHeight() || copyBox[i].getWidth() >= copyBox[i + 1].getWidth()) {
			return false;
		}
	}

	return true;
}

bool operator==(const Box& box1, const Box& box2)
{
	return box2.getHeight() == box1.getHeight()
		&& box2.getLength() == box1.getLength()
		&& box2.getValue() == box1.getValue()
		&& box1.getWeight() == box2.getWeight()
		&& box2.getWidth() == box1.getWidth();
}

std::istream& operator>>(std::istream& in, Box& box)
{
	int length, width, height;
	double weight;
	int value;

	in >> length >> width >> height >> weight >> value;

	box.setLength(length);
	box.setWidth(width);
	box.setHeight(height);
	box.setWeight(weight);
	box.setValue(value);

	return in;
}


std::ostream& operator<<(std::ostream& out, Box& box)
{
	out << "Длина: " << box.getLength() << "; ширина: " << box.getWidth() << "; высота: " << box.getHeight() << "; вес: " << box.getWeight() << "; цена содержимого: " << box.getValue();
	return out;
}