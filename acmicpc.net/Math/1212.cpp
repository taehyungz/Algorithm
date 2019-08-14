#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;
string Maketo2(int ch8, int pos) {
	string str = "";
	while (ch8 != 0) {
		str = to_string(ch8 % 2) + str;
		ch8 = ch8 / 2;
	}
	while (str.size() != 3 && pos != 0) {
		str = '0' + str;
	}
	return str;
}
int main() {
	string str_8;
	stack<string> strst;
	cin >> str_8;
	if (str_8[0] == '0') {
		cout << '0';
		return 0;
	}
	for (int i = str_8.size() - 1; i >= 0; i--) strst.push(Maketo2(str_8[i] - '0', i));
	while (!strst.empty()) {
		cout << strst.top();
		strst.pop();
	}
	return 0;
}