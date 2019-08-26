#include <iostream>
using namespace std;
long long dp[91];//n개 팔아서 얻는 수익
long long DP(int n) {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << DP(n);
}