#include "stdafx.h"
#include "DateConverter.h"


int DateConverter::ConvertDate(std::string &dateIn, std::string& dateOut)
{
	if (dateIn.size() != 5)
	{
		// неверный формат строки
		return 1;
	}

	int j = 0;
	int dd = 0;
	int mm = 0;
	for (std::string::iterator it = dateIn.begin(); it != dateIn.end(); ++it)
	{
		if (*it != '.')
		{
			switch (j)
			{
			case 0: dd = dd + (*it - 48) * 10; break;
			case 1: dd = dd + (*it - 48); break;
			case 3: mm = mm + (*it - 48) * 10; break;
			case 4: mm = mm + (*it - 48); break;
			default:
				break;
			}
		}
		++j;
	}

	if (dd < 0 || dd > 31 || mm < 1 || mm > 12)
	{
		// неверное число дней или месяцев
		return 2;
	}

	if ((dd > 29 && mm == 2) ||
		(dd > 30 && mm == 4) ||
		(dd > 30 && mm == 6) ||
		(dd > 30 && mm == 9) ||
		(dd > 30 && mm == 11))
	{
		//неверная дата
		return 3;
	}

	dd += 3;

	switch (mm)
	{
	case 1:  if (dd > 31) { dd -= 31; mm = 2; }; break;
	case 2:  if (dd > 29) { dd -= 29; mm = 3; }	break;
	case 3:  if (dd > 31) { dd -= 31; mm = 4; }	break;
	case 4:  if (dd > 30) { dd -= 30; mm = 5; }	break;
	case 5:  if (dd > 31) { dd -= 31; mm = 6; }	break;
	case 6:  if (dd > 30) { dd -= 30; mm = 7; }	break;
	case 7:  if (dd > 31) { dd -= 31; mm = 8; }	break;
	case 8:  if (dd > 31) { dd -= 31; mm = 9; }	break;
	case 9:  if (dd > 30) { dd -= 30; mm = 10; } break;
	case 10:  if (dd > 31) { dd -= 31; mm = 11; }	break;
	case 11:  if (dd > 30) { dd -= 30; mm = 12; }	break;
	case 12:  if (dd > 31) { dd -= 31; mm = 1; }	break;
	default:
		break;
	}

	std::string dateString;
	switch (dd)
	{
	case 1: dateString = "первое ";	break;
	case 2: dateString = "второе ";	break;
	case 3: dateString = "третье ";	break;
	case 4: dateString = "четвертое ";	break;
	case 5: dateString = "пятое ";	break;
	case 6: dateString = "шестое ";	break;
	case 7: dateString = "седьмое ";	break;
	case 8: dateString = "восьмое ";	break;
	case 9: dateString = "девятое ";	break;
	case 10: dateString = "десятое ";	break;
	case 11: dateString = "одиннадцатое ";	break;
	case 12: dateString = "двенадцатое ";	break;
	case 13: dateString = "тринадцатое ";	break;
	case 14: dateString = "четырнадцатое ";	break;
	case 15: dateString = "пятнадцатое ";	break;
	case 16: dateString = "шестнадцатое ";	break;
	case 17: dateString = "семнадцатое ";	break;
	case 18: dateString = "восемнадцатое ";	break;
	case 19: dateString = "девятнадцатое ";	break;
	case 20: dateString = "двадцатое ";	break;
	case 21: dateString = "двадцать первое ";	break;
	case 22: dateString = "двадцать второе ";	break;
	case 23: dateString = "двадцать третье ";	break;
	case 24: dateString = "двадцать четвертое ";	break;
	case 25: dateString = "двадцать пятое ";	break;
	case 26: dateString = "двадцать шестое ";	break;
	case 27: dateString = "двадцать седьмое ";	break;
	case 28: dateString = "двадцать восьмое ";	break;
	case 29: dateString = "двадцать девятое ";	break;
	case 30: dateString = "тридцатое ";	break;
	case 31: dateString = "тридцать первое ";	break;
	default:
		break;
	}

	std::string monthString;

	switch (mm)
	{
	case 1: monthString = "января"; break;
	case 2: monthString = "февраля"; break;
	case 3: monthString = "марта"; break;
	case 4: monthString = "апреля"; break;
	case 5: monthString = "мая"; break;
	case 6: monthString = "июня"; break;
	case 7: monthString = "июля"; break;
	case 8: monthString = "августа"; break;
	case 9: monthString = "сентября"; break;
	case 10: monthString = "октября"; break;
	case 11: monthString = "ноября"; break;
	case 12: monthString = "декабря"; break;
	default:
		break;
	}

	dateOut = dateString + monthString;
	return 0;
}
