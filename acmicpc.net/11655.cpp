#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + (s[i] < 'N' ? 13 : -13);
		else if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] + (s[i] < 'n' ? 13 : -13);
		else continue;
	}
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
	}
}