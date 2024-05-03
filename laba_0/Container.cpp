#include "Container.h"

namespace BoxAndContainer {
	Container::Container(int length, int width, int height, double maxWeight) : length(length), width(width), height(height), maxWeight(maxWeight) {}

	Container::Container() : length(0), width(0), height(0), maxWeight(0) {}

	int Container::getLength() const {
		return length;
	}
	int Container::getWidth() const {
		return width;
	}
	int Container::getHeight() const {
		return height;
	}
	double Container::getMaxWeight() const {
		return maxWeight;
	}

	void Container::setLength(int length) {
		if (length <= 0) {
			throw std::exception("Длина отрицательная или равна 0");
		}
		this->length = length;
	}
	void Container::setWidth(int width) {
		if (width <= 0) {
			throw std::exception("Ширина отрицательная или равна 0");
		}
		this->width = width;
	}
	void Container::setHeight(int height) {
		if (height <= 0) {
			throw std::exception("Высота отрицательная или равна 0");
		}
		this->height = height;
	}
	void Container::setMaxWeight(double maxWeight) {
		if (maxWeight <= 0) {
			throw std::exception("Масса отрицательная или равна 0");
		}
		this->maxWeight = maxWeight;
	}


	int Container::count() const {
		return vector.size();
	}

	double Container::totalWeight() const {
		double sumOfWeight = 0;

		for (const auto& box : vector) { 
			sumOfWeight += box.getWeight();
		}

		return sumOfWeight;
	}

	int Container::totalCost() const {
		int sumOfValue = 0;

		for (const auto& box : vector) {
			sumOfValue += box.getValue();
		}

		return sumOfValue;
	}

	Box Container::getBox(int i) const {
		return vector.at(i);
	}

	int Container::addBox(Box& box) {
		if (box.getWeight() + totalWeight() > this->maxWeight) {
			throw OutOfMaxExeption("Масса коробок превосходит максимальную грузоподъемность контейнера");
		}
		vector.push_back(box);
		return count();
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
				container.addBox(box);
			}
			catch (OutOfMaxExeption& e) {
				std::cout << "Масса коробки выходит за пределы допустимой грузоподъемности!!!";
				break;
			}
		}
		return in;
	}


	std::ostream& operator<<(std::ostream& out, const Container& container)
	{
		out << "Длина: " << container.getLength() << "; ширина: " << container.getWidth() << "; высота: " << container.getHeight() << "; максимально допустимый вес: " << container.getMaxWeight() << std::endl;
		for (int i = 0; i < container.count(); i++) {
			out << "Коробка # " << i + 1 << ":  " << container.getBox(i) << std::endl;
		}
		return out;
	}

	Box& Container::operator[](const int i) {
		return vector[i];
	}
}