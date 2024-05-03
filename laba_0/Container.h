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
		int length;
		int width;
		int height; //длина, ширина и высота коробки в см
		double maxWeight; //ограничение на максимальный вес контейнера

	public:
		Container(int length, int width, int height, double maxWeight);
		Container();

		int count() const; 	//Количество коробок в контейнере
		double totalWeight() const;  	//Суммарный вес содержимого коробок
		int totalCost() const;  	//Сумарная стоймость содержимого коробок
		Box getBox(int i) const;  	//Получение коробки по индексу
		int addBox(Box& box);  //Добавление коробки
		void deleteBox(int i);  //Удаление коробки по индексу
		Box& operator[](const int i);  //возвращение i-го элемента

		int getLength() const;
		int getWidth() const;
		int getHeight() const;
		double getMaxWeight() const;

		void setLength(int length);
		void setWidth(int width);
		void setHeight(int height);
		void setMaxWeight(double maxWeight);
	};

	class OutOfMaxExeption : public std::exception {
	public:
		OutOfMaxExeption(const char* theMessage) : exception(theMessage) { }
	};

	std::istream& operator>>(std::istream& in, Container& container);  //Оператор ввода
	std::ostream& operator<<(std::ostream& out, const Container& container);  //Оператор вывода
}