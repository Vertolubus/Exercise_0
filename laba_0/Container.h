#pragma once

#include <iostream>
#include <vector>
#include "Box.h"

namespace BoxAndContainer {
	//������� 10. ����� Container
	class  Container
	{
	private:
		std::vector<Box> vector;
		int length, width, height; //�����, ������ � ������ ������� � ��
		double maxWeight; //����������� �� ������������ ��� ����������

	public:
		Container(int length, int width, int height, double maxWeight);
		Container();

		int boxCounter() const; 	//���������� ������� � ����������
		double totalWeight();  	//��������� ��� ����������� �������
		int totalCost();  	//�������� ��������� ����������� �������
		Box getBox(int i) const;  	//��������� ������� �� �������
		int addingABox(Box& box);  //���������� �������
		void deleteBox(int i);  //�������� ������� �� �������
		Box& operator[](const int i);  //����������� i-�� ��������

		int getLength() const { return length; }
		int getWidth() const { return width; }
		int getHeight() const { return height; }
		double getMaxWeight() const { return maxWeight; }

		void setLength(int length) {
			if (length <= 0) throw std::exception("����� ������������� ��� ����� 0");
			this->length = length;
		}
		void setWidth(int width) {
			if (width <= 0) throw std::exception("������ ������������� ��� ����� 0");
			this->width = width;
		}
		void setHeight(int height) {
			if (height <= 0) throw std::exception("������ ������������� ��� ����� 0");
			this->height = height;
		}
		void setMaxWeight(double maxWeight) {
			if (maxWeight <= 0) throw std::exception("����� ������������� ��� ����� 0");
			this->maxWeight = maxWeight;
		}
	};

	std::istream& operator>>(std::istream& in, Container& container);  //�������� �����
	std::ostream& operator<<(std::ostream& out, const Container& container);  //�������� ������
}