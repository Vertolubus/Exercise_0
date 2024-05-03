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
		int length;
		int width;
		int height; //�����, ������ � ������ ������� � ��
		double maxWeight; //����������� �� ������������ ��� ����������

	public:
		Container(int length, int width, int height, double maxWeight);
		Container();

		int count() const; 	//���������� ������� � ����������
		double totalWeight() const;  	//��������� ��� ����������� �������
		int totalCost() const;  	//�������� ��������� ����������� �������
		Box getBox(int i) const;  	//��������� ������� �� �������
		int addBox(Box& box);  //���������� �������
		void deleteBox(int i);  //�������� ������� �� �������
		Box& operator[](const int i);  //����������� i-�� ��������

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

	std::istream& operator>>(std::istream& in, Container& container);  //�������� �����
	std::ostream& operator<<(std::ostream& out, const Container& container);  //�������� ������
}