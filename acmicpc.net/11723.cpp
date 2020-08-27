#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M;
	cin >> M;
	int n;
	string s;
	vector<int> vc;
	while (M--) {
		cin >> s;
		if (strcmp(s, "all")==0) {
			vc.clear();
			for (int i = 1; i <= 20; i++) vc.push_back(i);
		}
		else if (strcmp(s, "empty")) vc.clear();
		else {
			int i;
			for (i = 0; i < s.length; i++) if (s[i] == ' ') break;
			order = s[0:i];
			cout << order;
		}
	}
}