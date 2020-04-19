#include <iostream>
#include <vector>
using namespace std;
// d[n] = d[n-1]*2 + d[n-2]*3 + 2*(d[n-3]+d[n-4]+~~+d[0])
long long dp[1000001];
long long mul2dp[1000001];
int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	mul2dp[0] = dp[0] * 2;
	dp[1] = 2;
	mul2dp[1] = mul2dp[0] + dp[1] * 2;
	dp[2] = 7;
	mul2dp[2] = mul2dp[1] + dp[2] * 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 3 + mul2dp[i - 3]) % 1000000007;
		mul2dp[i] = (mul2dp[i - 1] + dp[i] * 2) % 1000000007;
	}
	cout << dp[n];
}