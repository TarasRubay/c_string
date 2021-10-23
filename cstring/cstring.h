#pragma once
#include<iostream>
#include<string>
using namespace std;
class cstring
{
	char* str;
	int length = 0;
public:
	cstring();
	cstring(const cstring& obj);
	cstring(const char *_str);
	~cstring();
	int lenstr(const char* _str);
	cstring& operator=(const char* _str);
	cstring& operator=(const cstring &obj);
	cstring& down_reg();
	cstring& up_reg();
	void output(ostream& out) const;
	friend istream& operator>>(istream& in, cstring& obj);
	friend ostream& operator<<(ostream& out, cstring& obj);
	bool operator==(cstring& obj);
	bool operator!=(cstring& obj);
	bool operator<(cstring& obj);
	bool operator>(cstring& obj);
	cstring& operator+=(cstring& obj);
	friend cstring operator+(const cstring& obj, const cstring& obj2);
};

