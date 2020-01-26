#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class String
{
protected:
	string str;
public:
	String(string str);
	~String();
};

class StringBit : public String
{

};

String::String(string str)
{
	this->str = str;
	int length = strlen(str);
	string *str = new string[length];
}

String::~String()
{
	delete str;
}

int main()
{
	setlocale(LC_ALL, "ru");



	system("pause");
	return 0;
}