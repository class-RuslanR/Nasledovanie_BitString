#include "pch.h"
#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNING

using namespace std;

class String
{
protected:
	int length;
	char *str;
public:
	String();
	String(char *strLiter);
	String(char symbol);
	void setStr(char *strLiter);
	char * getStr();
	int GetLength_String();
	void ClearString();
	void ShowString();
	~String();
};

String::String()
{
	str = new char('\0');
}

String::String(char * strLiter)
{
	str = new char[strlen(strLiter)+1];
	//strcpy(str, strLiter);
}

String::String(char symbol)
{
	str = new char;
	str[0] = symbol;
	str[1] = '\0';
	length = 1;
}

void String::setStr(char * strLiter)
{
	str = new char[length];
	for (int i = 0; i < length; i++)
	{
		if (strLiter[i] != '0' && strLiter[i] != '1')
		{
			str[i] = '0';
		}
		else
		{
			str[i] = strLiter[i];
		}
	}
	//strcpy(str, strLiter);
	//strcpy_s(str, _countof(str), strLiter);
}

char * String::getStr()
{
	cout << "Введите бинарную строку: ";
	cin >> str;
	length = strlen(str);
	setStr(str);
	return str;
}

int String::GetLength_String()
{
	return length;
}

void String::ClearString()
{
	delete str;
	length = 0;
	str = 0;
}

void String::ShowString()
{
	cout <<"Бинарная строка: " << "\n";
	for (int i = 0; i < length; i++)
	{
		cout << str[i];
	}
	cout << "\n\n";
}

String::~String()
{

}

class StringBit : public String
{
public:
	StringBit();
	StringBit(char *strLiter) : String(strLiter)
	{
		for (int i = 0; strLiter[i] < length; i++)
		{
			if (strLiter[i] != '0' && strLiter[i] != '1')
			{
				str[i] = '0';
			}
			else
			{
				str[i] = strLiter[i];
			}
		}
		for (int i = 0; i != '\0'; i++)
		{
			cout << str[i];
		}
	}
	~StringBit();
	char * changeNeg_or_Pos();
	StringBit operator = (StringBit & str2); 
	int SumStr(char * str1, char * str2);
	bool operator== (StringBit str2);
	void ShowStringPrisv();
};

StringBit::StringBit()
{
	String();
}

StringBit::~StringBit()
{
	String ::~String();
}

char * StringBit::changeNeg_or_Pos()
{

	if (str[0] == '-')
	{
		for (int i = 0; str[i] <= length; i++)
		{
			str[i] = str[i + 1];
		}
		length -= 1;
		str = new char[length];
		return str;
	}
	else if (str[0] == '0' || str[0] == '1')
	{
		length += 1;
		str = new char[length];
		for (int i = length; str[i] >= 0; i--)
		{
			str[i] = str[i - 1];
			if (str[0])
			{
				str[0] = '-';
			}
		}
		return str;
	}
}

StringBit StringBit::operator=(StringBit & str2)
{
	if (strlen(str) != strlen(str2.str))
	{
		int count = 0;
		delete str;
		for (int i = 0; str2.str[i] != '\0'; i++)
		{
			if (str2.str[i] == '0' || str2.str[i] == '1')
			{
				count++;
			}
		}
		for (int j = 0; j <= count; j++)
		{
			str[j] = str2.str[j];
		}
	}
	else
	{
		for (int i = 0; i <= length; i++)
		{
			str[i] = str2.str[i];
		}
	}
	return str;
}

int StringBit:: SumStr(char * str1, char * str2)
{
	int temp;
	int strToint_1 = atoi(str1);
	int strToint_2 = atoi(str2);
	int sum1 = 0, sum2 = 0;
	while (strToint_1)
	{
		sum1 += strToint_1 % 10;
		strToint_1 /= 10;
	}
	while (strToint_2)
	{
		sum2 += strToint_2 % 10;
		strToint_2 /= 10;
	}
	temp = sum1 + sum2;
	cout << "Сумма чисел строк= " << temp << "\n\n";
	return temp;
}

bool StringBit::operator== (StringBit str2)
{
	if (strlen(str) == strlen(str2.str))
	{
		for (int i = 0; i < length; i++)
		{
			if (str[i] == str2.str[i])
			{
				cout << "Строки одинаковы!" << "\n" << endl;
				return true;
			}
			else
			{
				cout << "Cтроки не равны" << "\n" << endl;
				return false;
			}
		}
	}
	else
	{
		cout << "Cтроки не равны" << "\n" << endl;
		return false;
	}
}

void StringBit::ShowStringPrisv()
{
	cout << "Бинарная строка: " << "\n";
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '0' || str[i] == '1')
		{
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << str[i];
	}
	cout << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "ru");

	StringBit stroka1;
	char *str_bit1 = stroka1.getStr();
	stroka1.ShowString();

	StringBit stroka2;
	char *str_bit2 = stroka2.getStr();
	stroka2.ShowString();

	cout << "Операция суммирования: " << endl;
	StringBit sumStr;
	sumStr.SumStr(str_bit1, str_bit2);

	cout << "Операция проверка на равенство: " << endl;
	stroka1 == stroka2;

	cout << "Операция присваивания: " << endl;
	stroka1 = stroka2;
	stroka1.ShowStringPrisv();
	
	system("pause");
	return 0;
}


