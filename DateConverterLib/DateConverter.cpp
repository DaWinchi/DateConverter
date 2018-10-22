#include "stdafx.h"
#include "DateConverter.h"


int DateConverter::ConvertDate(std::string &dateIn, std::string& dateOut)
{
	if (dateIn.size() != 5)
	{
		// �������� ������ ������
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
		// �������� ����� ���� ��� �������
		return 2;
	}

	if ((dd > 29 && mm == 2) ||
		(dd > 30 && mm == 4) ||
		(dd > 30 && mm == 6) ||
		(dd > 30 && mm == 9) ||
		(dd > 30 && mm == 11))
	{
		//�������� ����
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
	case 1: dateString = "������ ";	break;
	case 2: dateString = "������ ";	break;
	case 3: dateString = "������ ";	break;
	case 4: dateString = "��������� ";	break;
	case 5: dateString = "����� ";	break;
	case 6: dateString = "������ ";	break;
	case 7: dateString = "������� ";	break;
	case 8: dateString = "������� ";	break;
	case 9: dateString = "������� ";	break;
	case 10: dateString = "������� ";	break;
	case 11: dateString = "������������ ";	break;
	case 12: dateString = "����������� ";	break;
	case 13: dateString = "����������� ";	break;
	case 14: dateString = "������������� ";	break;
	case 15: dateString = "����������� ";	break;
	case 16: dateString = "������������ ";	break;
	case 17: dateString = "����������� ";	break;
	case 18: dateString = "������������� ";	break;
	case 19: dateString = "������������� ";	break;
	case 20: dateString = "��������� ";	break;
	case 21: dateString = "�������� ������ ";	break;
	case 22: dateString = "�������� ������ ";	break;
	case 23: dateString = "�������� ������ ";	break;
	case 24: dateString = "�������� ��������� ";	break;
	case 25: dateString = "�������� ����� ";	break;
	case 26: dateString = "�������� ������ ";	break;
	case 27: dateString = "�������� ������� ";	break;
	case 28: dateString = "�������� ������� ";	break;
	case 29: dateString = "�������� ������� ";	break;
	case 30: dateString = "��������� ";	break;
	case 31: dateString = "�������� ������ ";	break;
	default:
		break;
	}

	std::string monthString;

	switch (mm)
	{
	case 1: monthString = "������"; break;
	case 2: monthString = "�������"; break;
	case 3: monthString = "�����"; break;
	case 4: monthString = "������"; break;
	case 5: monthString = "���"; break;
	case 6: monthString = "����"; break;
	case 7: monthString = "����"; break;
	case 8: monthString = "�������"; break;
	case 9: monthString = "��������"; break;
	case 10: monthString = "�������"; break;
	case 11: monthString = "������"; break;
	case 12: monthString = "�������"; break;
	default:
		break;
	}

	dateOut = dateString + monthString;
	return 0;
}
