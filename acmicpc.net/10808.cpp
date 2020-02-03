#include <iostream>
#include <string>
using namespace std;
int counts[26];
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		counts[s[i] - 'a']++;
	}
	for (int i = 0; i < sizeof(counts) / sizeof(int); i++) {
		cout << counts[i] << ' ';
	}
	return 0;
}