#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long d[5001];
int mod = 1000000;

long long DP(string N) {
	d[0] = 1;
	int len = N.size();
	N = " " + N;
	for (int i = 1; i <= len; i++) {
		int x = N[i] - '0';
		if (x >= 1 && x <= 9) {
			d[i] += d[i - 1];
			d[i] %= mod;
		}
		if (i == 1) continue;//두 자리수 이기 때문에
		if (N[i - 1] == '0') continue;
		x = (N[i - 1] - '0') * 10 + N[i] - '0';
		if (10 <= x && x <= 26) {
			d[i] += d[i - 2];
			d[i] %= mod;
		}
	}
	return d[len];
}
int main() {
	ios_base::sync_with_stdio(false);
	string N;
	cin >> N;
	cout << DP(N);
	return 0;
}