﻿#include "pch.h"
#include <iostream>
#include <string.h>

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
	int GetLength_String();
	void ClearString();
	void ShowString();
	~String();
};

String::String()
{
	str = new char;
	str[0] = '\0';
	length = 0;
}

String::String(char * strLiter)
{
	length = strlen(strLiter);
	char *str = new char[length];
	for (int i = 0; strLiter[i] != '\0'; i++)
	{
		if (strLiter[i] != '0' && strLiter[i] != '1')
		{
			strLiter[i] = '0';
		}
	}
	for (int i = 0; i != '\0'; i++)
	{
		str[i] = strLiter[i];
	}
	//strcpy(str, strLiter);
}

String::String(char symbol)
{
	str = new char;
	str[0] = symbol;
	str[1] = '\0';
	length = 1;
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
	cout << str << "\n\n";
}

String::~String()
{
	if (str)
	{
		delete str;
		str = 0;
	}
}

class StringBit : public String
{
public:
	StringBit();
	StringBit(char *strLiter) : String(strLiter)
	{
		cout << "Бинарная строка: ";
	}
	~StringBit();
	char * changeNeg_or_Pos();
	//StringBit operator = (StringBit & str2);
	//StringBit operator + (StringBit & str2);
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

/*StringBit StringBit::operator=(StringBit & str2)
{
	return StringBit();
}

StringBit StringBit::operator+(StringBit & str2)
{
		if (this == &str2)
		{
			return *this;
		}
		strcpy(str2.Data());
		return *this;
}
*/
StringBit *a;

int main()
{
	setlocale(LC_ALL, "ru");
	StringBit s1;
	s1.ShowString();
	char stroka[] = "0101";
	StringBit s2(stroka);
	s2.ShowString();


	system("pause");
	return 0;
}


