#include <iostream>
using namespace std;
int dp[11];
int DP(int n) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		cout << DP(k) << '\n';
	}
	return 0;
}