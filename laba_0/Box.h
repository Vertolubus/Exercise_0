#pragma once

#include <iostream>

//������� 1. ��������� Box � ������ � �����������.
class Box
{
private:
	int length, width, height; //�����, ������ � ������ ������� � ��
	double weight; //����� ������� � ��
	int value; // ��������� ����������� � ��������

public:
	Box(int length, int width, int height, double weight, int value);
	Box();

	int getLength() const { return length; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	double getWeight() const { return weight; }
	int getValue() const { return value; }

	void setLength(int length){
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
	void setWeight(double weight) {
		if (weight <= 0) throw std::exception("����� ������������� ��� ����� 0");
		this->weight = weight;
	}
	void setValue(int value) {
		if (value < 0) throw std::exception("��������� ����������� �������������");
		this->value = value;
	}
};


//������� 2. ���������� ��������� ��������� ������������ ���� �������.
int sumValue(Box box[], int n);

//������� 3. �������� ����, ��� ����� �����, ������ � ������ ���� ������� �� ����������� ��������� ��������.
//������� ���������� false, ���� ����� ��������� ���� ��� ��������� �� �������� ��������.
//������� ���������� true, ���� �������� �������� �� ���������.
bool lessThanTheSpecifiedValue(Box box[], int n, int maxValue);

//������� 4.  �������, ������� ���������� ������������ ��� �������, ����� ������� �� ������ ��������� maxV.
double volumCheck(Box box[], int n, int maxV);

//������� 5. ������� ���������, ����� �� ������� ���� ������� � ������, ������� � ����������, �������� ��, ��� �����, ������ � ������ ����� ������� 
//�� ����������� �������� ������.
bool matryoshka(Box box[], int n);

//������� 6. �������� c�������� ���� ������� �� ���� ����������.
bool operator==(const Box& box1, const Box& box2);

//������� 7. ��������� �����/������ (>> � <<) ��� ������� � ������������ ������. 
std::istream& operator>>(std::istream& in, Box& box);

std::ostream& operator<<(std::ostream& out, Box& box);