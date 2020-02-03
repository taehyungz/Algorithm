#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	vector<string> vc;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		string sub_s = "";
		for (int j = i; j < s.size(); j++) {
			sub_s += s[j];
		}
		vc.push_back(sub_s);
	}
	sort(vc.begin(), vc.end());
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[i].size(); j++) {
			cout << vc[i][j];
		}
		cout << '\n';
	}
	return 0;
}