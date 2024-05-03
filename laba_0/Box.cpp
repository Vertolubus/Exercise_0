#include "Box.h"

namespace BoxAndContainer {
	Box::Box(int length, int width, int height, double weight, int value) : length(length), width(width), height(height), weight(weight), value(value) {}

	Box::Box() : length(0), width(0), height(0), weight(0), value(0) {}

	int Box::getLength() const {
		return length;
	}
	int Box::getWidth() const {
		return width;
	}
	int Box::getHeight() const {
		return height;
	}
	double Box::getWeight() const
	{
		return weight;
	}
	int Box::getValue() const {
		return value;
	}

	void Box::setLength(int length) {
		if (length <= 0) {
			throw std::exception("Длина отрицательная или равна 0");
		}
		this->length = length;
	}
	void Box::setWidth(int width) {
		if (width <= 0) {
			throw std::exception("Ширина отрицательная или равна 0");
		}
		this->width = width;
	}
	void Box::setHeight(int height) {
		if (height <= 0) {
			throw std::exception("Высота отрицательная или равна 0");
		}
		this->height = height;
	}
	void Box::setWeight(double weight) {
		if (weight <= 0) {
			throw std::exception("Масса отрицательная или равна 0");
		}
		this->weight = weight;
	}
	void Box::setValue(int value) {
		if (value < 0) {
			throw std::exception("Стоймость содержимого отрицательная");
		}
		this->value = value;
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


	std::ostream& operator<<(std::ostream& out, const Box& box)
	{
		out << "Длина: " << box.getLength() << "; ширина: " << box.getWidth() << "; высота: " << box.getHeight() << "; вес: " << box.getWeight() << "; цена содержимого: " << box.getValue();
		return out;
	}
}