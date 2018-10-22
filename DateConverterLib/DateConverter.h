#pragma once
#include <string>
class DateConverter
{
public:
	/** �������� �����, ������� �������� ����� �������� init_time � ������� "HH:MM" + 5 �����,
	����� �������� new_time_str � ��������� �������������. ����������� ����, ������� �������� ����� �������� dateIn � ������� "DD.MM" �� 3 ���.
	* @param dateIn - ��������� ���� "DD.MM".
	* @param dateOut - ���� ����� 3 ��� � ��������� ������������� "����������� ����".
	*/
	static int ConvertDate(std::string &dateIn, std::string& dateOut);
};

