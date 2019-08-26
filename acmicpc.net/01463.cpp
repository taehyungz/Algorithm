#include <iostream>
using namespace std;
int dp[1000001];
int DP(int n) {
	if (n == 1) return 0;
	if (dp[n] > 0) return dp[n];
	dp[n] = DP(n - 1) + 1;
	if (n % 2 == 0) {
		int temp = DP(n / 2) + 1;
		if (dp[n] > temp) dp[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = DP(n / 3) + 1;
		if (dp[n] > temp) dp[n] = temp;
	}
	return dp[n];
}
int BUDP(int n) {
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i / 2] + 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) dp[i] = dp[i / 2] + 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) dp[i] = dp[i / 3] + 1;
	}
	return dp[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << DP(n);
	return 0;
}