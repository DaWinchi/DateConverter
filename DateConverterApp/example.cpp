#include <iostream>
#include "../DateConverterLib/DateConverter.h"

#pragma comment (lib, "../Debug/DateConverterLib.lib")
int main()
{
	setlocale(LC_ALL, "Russian");
	std::string in, out;

	while (true)
	{
		std::cout << "������� ����: ";
		std::cin >> in;

		DateConverter::ConvertDate(in, out);
		std::cout << "���������: " << out << std::endl;
	}
	system("pause");
}