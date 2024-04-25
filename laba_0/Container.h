#pragma once

#include <iostream>
#include <vector>
#include "Box.h"

namespace BoxAndContainer {
	//Задание 10. Класс Container
	class  Container
	{
	private:
		std::vector<Box> vector;
		int length, width, height; //длина, ширина и высота коробки в см
		double maxWeight; //ограничение на максимальный вес контейнера

	public:
		Container(int length, int width, int height, double maxWeight);
		Container();

		int boxCounter() const; 	//Количество коробок в контейнере
		double totalWeight();  	//Суммарный вес содержимого коробок
		int totalCost();  	//Сумарная стоймость содержимого коробок
		Box getBox(int i) const;  	//Получение коробки по индексу
		int addingABox(Box& box);  //Добавление коробки
		void deleteBox(int i);  //Удаление коробки по индексу
		Box& operator[](const int i);  //возвращение i-го элемента

		int getLength() const { return length; }
		int getWidth() const { return width; }
		int getHeight() const { return height; }
		double getMaxWeight() const { return maxWeight; }

		void setLength(int length) {
			if (length <= 0) throw std::exception("Длина отрицательная или равна 0");
			this->length = length;
		}
		void setWidth(int width) {
			if (width <= 0) throw std::exception("Ширина отрицательная или равна 0");
			this->width = width;
		}
		void setHeight(int height) {
			if (height <= 0) throw std::exception("Высота отрицательная или равна 0");
			this->height = height;
		}
		void setMaxWeight(double maxWeight) {
			if (maxWeight <= 0) throw std::exception("Масса отрицательная или равна 0");
			this->maxWeight = maxWeight;
		}
	};

	std::istream& operator>>(std::istream& in, Container& container);  //Оператор ввода
	std::ostream& operator<<(std::ostream& out, const Container& container);  //Оператор вывода
}