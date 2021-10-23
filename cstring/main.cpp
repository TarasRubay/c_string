#include "cstring.h"
int main() {
	cstring str("12345");
	cstring s;
	s = "qWeRtY";
	str = s;
	s.down_reg();
	s.up_reg();
	str.up_reg();
	cin >> s;
	cin >> str;
	str.up_reg();
	cout << str << endl;
	cout << s << endl;
	cstring t = s + str;
	cout << t << endl;
	cout << str << endl;
	s = t + str;
	cout << s << endl;
	str = s + t;
	s += str;
	cout << s << endl;
	bool a = s == t;
	cout << "\t\t\t\ts == t - " << boolalpha<< a << endl;
	a = s != t;
	cout << "\t\t\t\ts != t - " << boolalpha<< a << endl;
	a = s < t;
	cout << "\t\t\t\ts < t - " << boolalpha<< a << endl;
	a = s > t;
	cout << "\t\t\t\ts > t - " << boolalpha<< a << endl;
	return 0;
}