﻿#include <iostream>
#include "Box.h"
#include "Container.h"

using namespace BoxAndContainer;

int main()
{
	setlocale(LC_ALL, "Russian");
	Box* box = new Box[5];
	box[0] = Box(1, 2, 3, 4, 5);
	box[1] = Box(2, 3, 4, 5, 6);
	box[2] = Box(3, 4, 5, 6, 7);
	box[3] = Box(4, 5, 6, 7, 8);
	box[4] = Box(5, 6, 7, 8, 9);
	std::cout << "Суммарная стоимость: " << sumValue(box, 5) << " (Correct is 35)" << std::endl; //Задание 2.
	std::cout << "Не превосходят ли значения сумму длины, высоты и ширины всех коробок заданное значение:  "
		<< lessThanTheSpecifiedValue(box, 5, 99) << " (Correct is 1)" << std::endl; //Задание 3.
	std::cout << "Максимальный вес коробок, не превосходящий максимальный объем коробок: " << volumCheck(box, 5, 61)
		<< " (Correct is 6)" << std::endl; //Задание 4.
	std::cout << "Можно ли вложить одну коробку в другую, начиная с самой маленькой: " << matryoshka(box, 5) << " (Correct is 1)" << std::endl; //Задание 5.
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Коробка #" << i + 1 << std::endl;
		std::cout << box[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	/*std::cout << "Введите номер коробки, которую вы хотите изменить: ";
	int n;
	std::cin >> n;
	std::cout << std::endl;
	std::cout << "Введите новые значения: " << std::endl;
	std::cin >> box[n - 1];
	std::cout << "Новые параметры коробки #" << n - 1 << std::endl;
	std::cout << box[n - 1];
	*/

	Container container = Container(100, 50, 250, 35);

	std::cout << "Количество коробок: " << container.count() << " (Correct is 0)" << std::endl;

	container.addBox(box[0]);
	container.addBox(box[1]);
	container.addBox(box[2]);
	container.addBox(box[3]);
	container.addBox(box[4]);

	std::cout << container;
	std::cout << "Количество коробок: " << container.count() << " (Correct is 5)" << std::endl;

	std::cout << "Суммарный вес содержимого в коробках: " << container.totalWeight() << " (Correct is 30)" << std::endl;
	std::cout << "Суммарная стоймость содержимого в коробках: " << container.totalCost() << " (Correct is 35)" << std::endl;

	std::cout << container.getBox(2) << " (Correct is Длина: 3; ширина: 4; высота: 5; вес: 6; цена содержимого : 7)" << std::endl;
	container.deleteBox(0);
	container.deleteBox(3);

	std::cout << container;
	std::cout << "Количество коробок: " << container.count() << " (Correct is 3)" << std::endl;

	std::cout << container[2] << std::endl;
	container[2] = box[4];
	std::cout << container[2] << std::endl;
	std::cout << "--------------" << std::endl;
	std::cin >> container;
	std::cout << container;

	try {
		container.setHeight(-1);
	}
	catch (std::exception) {
		std::cout << "Error! (It is correct)";
	}
}










// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.




	/*int n; //количество коробок
	int length, width, height; //длина, ширина и высота коробки в см
	double weight; //масса коробки в кг
	int value; //стоимость содержимого в копейках
	int maxLength, maxWidth, maxHeight; //предельные значения для длины, ширины и высоты коробки
	int maxV; //максимальный объем
	int n1, n2;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите количество коробок" << std::endl;
	std::cin >> n;
	Box* box = new Box[n];
	std::cout << "Введите длину, ширину, высоту, массу и стоймость содержимого коробки" << std::endl;
	for(int i = 0; i < n; i++)
	{
		std::cout << "Коробка #" << i + 1 << std::endl;
		std::cin >> box[i];
		std::cout << std::endl;
	}
	std::cout << "Суммарная стоимость: " << sumValue(box, n) << " (Correct is ?)" << std::endl; //Задание 2.
	std::cout << "Введите предельные значения, для длины, ширины и высоты коробок: " << std::endl;
	std::cin >> maxLength >> maxWidth >> maxHeight;
	std::cout << std::endl;
	//std::cout << "Не превосходят ли значения суммы длины, высоты и ширины всех коробок заданное значение:  " << lessThanTheSpecifiedValue(box, n, maxLength, maxWidth, maxHeight) << std::endl; //Задание 3.
	std::cout << "Введите максимальный объем коробок: ";
	std::cin >> maxV;
	std::cout << std::endl;
	std::cout << "Максимальный вес коробок, не превосходящий максимальный объем коробок: " << volumCheck(box, n, maxV) << std::endl; //Задание 4.
	std::cout << "Можно ли вложить одну коробку в другую, начиная с самой маленькой: " << matryoshka(box, n) << std::endl;
	std::cout << "Введите номера коробок, которые вы хотите сравнить: " << std::endl;
	std::cin >> n1 >> n2;
	std::cout << "Равны ли коробки по всем параметрам? " << operator==(box[n1 + 1], box[n2 + 1]) << " (Correct is 1)" << std::endl;
	std::cout << "Введите номер коробки, которую вы хотите изменить: ";
	std::cin >> n;
	std::cout << std::endl;
	std::cin >>  box[n + 1];
	std::cout << "Новые параметры коробки #" << n + 1 << std::endl;
	std::cout << box[n];
	delete[] box; */