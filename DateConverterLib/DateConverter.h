#pragma once
#include <string>
class DateConverter
{
public:
	/** Получить время, которое передано через параметр init_time в формате "HH:MM" + 5 минут,
	через параметр new_time_str в строковом представлении. Увеличивает дату, которая передана через параметр dateIn в формате "DD.MM" на 3 дня.
	* @param dateIn - начальная дата "DD.MM".
	* @param dateOut - дата через 3 дня в строковом представлении "двенадцатое июня".
	*/
	static int ConvertDate(std::string &dateIn, std::string& dateOut);
};

