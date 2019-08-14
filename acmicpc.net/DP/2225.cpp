#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long d[201][201];

long long DP(int N) {
	int K;
	cin >> K;
	d[0][0] = 1LL;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int t = 0; t <= j; t++) {
				d[i][j] += d[i - 1][j - t];
				d[i][j] %= 1000000000;
			}
		}
	}
	return d[K][N];
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}