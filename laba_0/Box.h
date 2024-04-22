#pragma once

#include <iostream>

//Задание 1. Структура Box с полями и конструктор.
class Box
{
private:
	int length, width, height; //длина, ширина и высота коробки в см
	double weight; //масса коробки в кг
	int value; // стоимость содержимого в копейках

public:
	Box(int length, int width, int height, double weight, int value);
	Box();

	int getLength() const { return length; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	double getWeight() const { return weight; }
	int getValue() const { return value; }

	void setLength(int length){
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
	void setWeight(double weight) {
		if (weight <= 0) throw std::exception("Масса отрицательная или равна 0");
		this->weight = weight;
	}
	void setValue(int value) {
		if (value < 0) throw std::exception("Стоймость содержимого отрицательная");
		this->value = value;
	}
};


//Задание 2. Вычисление суммарной стоимости содержиммого всех коробок.
int sumValue(Box box[], int n);

//Задание 3. Проверка того, что сумма длины, ширины и высоты всех коробок не превосходит заданного значения.
//Функция возвращает false, если сумма превысила одно или несколько из заданных значений.
//Функция возвращает true, если заданные значения не превышены.
bool lessThanTheSpecifiedValue(Box box[], int n, int maxValue);

//Задание 4.  Функция, которая определяет максимальный вес коробок, объем которых не больше параметра maxV.
double volumCheck(Box box[], int n, int maxV);

//Задание 5. Функция проверяет, можно ли вложить одну коробку в другую, начиная с наименьшей, учитывая то, что длина, ширина и высота одной коробки 
//не превосходит значения другой.
bool matryoshka(Box box[], int n);

//Задание 6. Оператор cравнения двух коробок по всем параметрам.
bool operator==(const Box& box1, const Box& box2);

//Задание 7. Операторы ввода/вывода (>> и <<) для коробок в произвольные потоки. 
std::istream& operator>>(std::istream& in, Box& box);

std::ostream& operator<<(std::ostream& out, Box& box);