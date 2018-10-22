#include <iostream>
#include "../DateConverterLib/DateConverter.h"

#pragma comment (lib, "../Debug/DateConverterLib.lib")
int main()
{
	setlocale(LC_ALL, "Russian");
	std::string in, out;

	while (true)
	{
		std::cout << "¬ведите дату: ";
		std::cin >> in;

		DateConverter::ConvertDate(in, out);
		std::cout << "–езультат: " << out << std::endl;
	}
	system("pause");
}