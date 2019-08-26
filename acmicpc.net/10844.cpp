#include <iostream>
using namespace std;
long long dp[101][10];
long long DP(int n) {
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j > 0 && j < 9) dp[i][j] = dp[i - 1][j - 1] % 1000000000 + dp[i - 1][j + 1] % 1000000000;
			else if (j == 0) dp[i][j] = dp[i - 1][1];
			else dp[i][j] = dp[i - 1][8];
		}
	}
	long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[n][i]) % 1000000000;
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << DP(n);
	return 0;
}