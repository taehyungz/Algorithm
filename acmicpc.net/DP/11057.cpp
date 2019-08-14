#include <iostream>
using namespace std;
int dp[1001][10];
int DP(int N) {
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++)
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[N][i]) % 10007;
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}