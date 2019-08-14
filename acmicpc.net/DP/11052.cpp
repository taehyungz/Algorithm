#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];//n개 팔아서 얻는 수익
int DP(int n) {
	dp[0] = 0;
	int *cost = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + cost[1];
		for (int j = 1; j <= i; j++)
			if (dp[i] < dp[i - j] + cost[j]) dp[i] = dp[i - j] + cost[j];
	}
	return dp[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << DP(n);
}