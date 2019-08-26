#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cin.ignore(256, '\n');
	string s;
	for (int i = 0; i < N; i++) {
		getline(cin, s);
		int count = 0;
		int score = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'O') {
				count++;
				score += count;
			}
			else if (s[j] == 'X') {
				count = 0;
			}
		}
		cout << score << '\n';
	}
}