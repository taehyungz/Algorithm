#include <iostream>
using namespace std;
long long dp[4][1000001];
int main() {
	int n, T;
	cin >> T;
	int max = 4;

	dp[1][1] = 1;
	dp[0][1] = 1;
	dp[2][2] = 1;
	dp[0][2] = 1;
	dp[1][3] = 1;
	dp[2][3] = 1;
	dp[3][3] = 1;
	dp[0][3] = 3;
	while (T--) {
		cin >> n;
		for (int i = max; i <= n; i++) {
			dp[1][i] = (dp[2][i - 1] + dp[3][i - 1]) % 1000000009;
			dp[2][i] = (dp[1][i - 2] + dp[3][i - 2]) % 1000000009;
			dp[3][i] = (dp[1][i - 3] + dp[2][i - 3]) % 1000000009;
			dp[0][i] = ((dp[1][i] + dp[2][i]) % 1000000009 + dp[3][i]) % 1000000009;
		}
		if (n >= max) max = n + 1;
		cout << dp[0][n] << '\n';
	}
}