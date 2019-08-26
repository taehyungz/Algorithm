#include <iostream>
#include <algorithm>
using namespace std;
int score[2][100001];
int dp[3][100001];
int DP(int n) {
	for (int i = 1; i <= n; i++) cin >> score[0][i];
	for (int i = 1; i <= n; i++) cin >> score[1][i];

	for (int i = 1; i <= n; i++) {
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		dp[0][i] = max(dp[0][i], dp[2][i - 1]);
		dp[1][i] = max(dp[0][i - 1] + score[0][i], dp[2][i - 1] + score[0][i]);
		dp[2][i] = max(dp[0][i - 1] + score[1][i], dp[1][i - 1] + score[1][i]);
	}
	int sum = max(dp[0][n], dp[1][n]);
	sum = max(sum, dp[2][n]);
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << DP(n) << '\n';
	}
	return 0;
}