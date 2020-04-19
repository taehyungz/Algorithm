#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string s1, string s2) {
	if (s1.length() < s2.length()) return true;
	else if (s1.length() > s2.length()) return false;
	else {
		return s1 < s2;
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
		if (i > 0 && vc[i] == vc[i - 1]) continue;
		cout << vc[i] << '\n';
	}
}