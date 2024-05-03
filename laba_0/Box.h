#pragma once

#include <iostream>

namespace BoxAndContainer {
	//������� 1. ��������� Box � ������ � �����������.
	class Box
	{
	private:
		int length; //�����
		int width; //������
		int height; //������ 
		double weight; //����� ������� � ��
		int value; // ��������� ����������� � ��������

	public:
		Box(int length, int width, int height, double weight, int value);
		Box();

		int getLength() const;
		int getWidth() const;
		int getHeight() const;
		double getWeight() const;
		int getValue() const;

		void setLength(int length);
		void setWidth(int width);
		void setHeight(int height);
		void setWeight(double weight);
		void setValue(int value);
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

	std::ostream& operator<<(std::ostream& out, const Box& box);
}