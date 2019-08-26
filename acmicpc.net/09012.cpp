#include <iostream>
#include <string>
using namespace std;

string valid(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) return "NO";
	}
	if (cnt == 0) return "YES";
	else return "NO";
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		cout << valid(s) << '\n';
	}
	return 0;
}