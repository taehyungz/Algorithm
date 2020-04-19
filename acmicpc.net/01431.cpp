#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string s1, string s2) {
	if (s1.length() < s2.length()) return true;
	else if (s1.length() > s2.length()) return false;
	else {
		int num1 = 0, num2 = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] >= '0' && s1[i] <= '9') num1 = num1 + s1[i] - '0';
		}
		for (int i = 0; i < s2.length(); i++) {
			if (s2[i] >= '0' && s2[i] <= '9') num2 = num2 + s2[i] - '0';
		}
		if (num1 < num2) return true;
		else if (num1 > num2) return false;
		else return s1 < s2;
	}
}
int main() {
	int n;
	vector<string> vc;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vc.push_back(s);
	}
	sort(vc.begin(), vc.end(), cmp);
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << '\n';
	}
}