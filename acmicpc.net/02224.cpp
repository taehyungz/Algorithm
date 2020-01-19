#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;
int defs[52][52];
int answer[2704][2];//52*52
vector<int> vc[2];
//A : 65 Z:90 a:97 z:122 -> A:0 Z:25 a:26 z:52
int CharToInt(char c) {
	return c >= 'A' && c <= 'Z' ? c - 'A' : c - 'a' + 26;
}
char IntToChar(int n) {
	return n < 26 ? n + 'A' : n + 'a' - 26;
}
int main() {
	int N;
	cin >> N;
	int count = 0;

	fill_n(&defs[0][0], sizeof(defs) / sizeof(int), MAX);
	for (int i = 0; i <= 51; i++) {
		defs[i][i] = 1;
	}
	while (N--) {
		char a, b;
		int c, d;
		cin >> a;
		cin >> b;
		cin >> b;
		cin >> b;
		c = CharToInt(a);
		d = CharToInt(b);
		defs[c][d] = 1;
	}
	for (int k = 0; k <= 51; k++) {
		for (int i = 0; i <= 51; i++) {
			for (int j = 0; j <= 51; j++) {
				if (defs[i][j] > defs[i][k] + defs[k][j]) {
					defs[i][j] = defs[i][k] + defs[k][j];
				}
			}
		}
	}
	for (int i = 0; i <= 51; i++) {
		for (int j = 0; j <= 51; j++) {
			if (defs[i][j] < MAX && i != j) {
				answer[count][0] = i;
				answer[count++][1] = j;
			}
		}
	}
	cout << count << '\n';
	for (int i = 0; i < count; i++) {
		cout << IntToChar(answer[i][0]) << " => " << IntToChar(answer[i][1]) << '\n';
	}
	return 0;
}