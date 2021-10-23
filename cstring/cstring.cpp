#include "cstring.h"

cstring::cstring()
{
	cout << "constructor without param  "<< this << endl;
	str = nullptr;

}

cstring::cstring(const cstring& obj)
{
	cout << "constructor copy " << this << endl;
	this->length = lenstr(obj.str);
	this->str = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
	{
		this->str[i] = obj.str[i];
	}
	this->str[this->length] = '\0';
}

int cstring::lenstr(const char* _str)
{
	cout << "length funct " << this << endl;
	int i = 0;
	while (_str[i] != '\0')
	{
		++i;
	}
	return this->length = i;
}


cstring::cstring(const char* _str)
{
	cout << "constructor with param char " << this << endl;
	length = lenstr(_str);
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = _str[i];
	}
	str[length] = '\0';
}

cstring::~cstring()
{
	cout << "destructor in <<" << this << endl;
	if(str != nullptr){
		cout << "destr in if !!" << this << endl;
		delete[] str;
	    str = nullptr;
		length = 0;
	}
	cout << "destructor  out >>" << this << endl;
	
}

cstring& cstring::operator=(const char* _str)
{
	if (this->str != nullptr) 
		this->~cstring();

	length = lenstr(_str);
	str = new char[length+1];
	for (int i = 0; i < length; i++)
	{
		str[i] = _str[i];
	}
	str[length] = '\0';
	return *this;
}

cstring& cstring::operator=(const cstring &obj)
{
	if (this->str != nullptr) 
		this->~cstring();

	this->length = lenstr(obj.str);
	this->str = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
	{
		this->str[i] = obj.str[i];
	}

	this->str[this->length] = '\0';
	return *this;
}

cstring& cstring::down_reg()
{
	for (int i = 0; i < length; i++)
	{
		if (this->str[i] >= 65 && this->str[i] <= 90) {
			int a = (int(this->str[i]) - 65) + 97;
			this->str[i] = a;
		}
	}
	return *this;
}

cstring& cstring::up_reg()
{
	for (int i = 0; i < length; i++)
	{
		if (this->str[i] >= 97 && this->str[i]	<= 122) {
			int a = (int(this->str[i]) - 97) + 65;
			this->str[i] = a;
		}
	}
	return *this;
}

void cstring::output(ostream& out) const
{
	int i = 0;
	while (str[i] != '\0') {
		cout << str[i];
		++i;
	}
}

bool cstring::operator==(cstring& obj)
{
	if (lenstr(this->str) == lenstr(obj.str))return true;
	else return false;
}

bool cstring::operator!=(cstring& obj)
{
	return !this->operator==(obj);
}

bool cstring::operator<(cstring& obj)
{
	if (lenstr(this->str) < lenstr(obj.str))return true;
	else return false;
}

bool cstring::operator>(cstring& obj)
{
	return !this->operator<(obj);
}

cstring& cstring::operator+=(cstring& obj)
{
	cstring tmp;
	tmp.length = this->length + obj.length;
	tmp.str = new char[tmp.length + 1];
	for (int i = 0; i < tmp.length; i++)
	{
		if (i < this->length)tmp.str[i] = this->str[i];
		else tmp.str[i] = obj.str[i-(this->length)];
	}
	tmp.str[tmp.length] = '\0';
	*this = tmp;
	return *this;
}




istream& operator>>(istream& in, cstring& obj)
{	
	cstring tmp;
	tmp.str = new char[1024];
	cin >> tmp.str;
	tmp.length = tmp.lenstr(tmp.str);
	obj = tmp;
	return in;
}

ostream& operator<<(ostream& out, cstring& obj)
{
	obj.output(out);
	return out;
}

cstring operator+(const cstring& obj, const cstring& obj2)
{
	cstring tmp;
	tmp.length = obj.length + obj2.length;
	tmp.str = new char[tmp.length + 1];
	for (int i = 0; i < tmp.length; i++)
	{
		if (i < obj.length)tmp.str[i] = obj.str[i];
		else tmp.str[i] = obj2.str[i - (obj.length)];
	}
	tmp.str[tmp.length] = '\0';
	return tmp;
}

