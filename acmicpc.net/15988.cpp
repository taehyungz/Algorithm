using namespace std;
long long dp[1000001];
int main() {
	int T, n;
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int next = 4;
	while (T--) {
		cin >> n;

		for (int i = next; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		}
		next = next < n ? n : next;
		cout << dp[n] << '\n';
	}
}