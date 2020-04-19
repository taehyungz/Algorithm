#include <iostream>
#include <algorithm>
using namespace std;
int costs[1000][3];
int dp[1000][3];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> costs[i][j];
		}
	}
	int minsum = 1000000;
	for (int k = 0; k < 3; k++) {
		dp[0][0] = 1000000;
		dp[0][1] = 1000000;
		dp[0][2] = 1000000;
		if (k == 0) dp[0][0] = costs[0][0];
		else if (k == 1) dp[0][1] = costs[0][1];
		else dp[0][2] = costs[0][2];
		for (int idx = 1; idx < N; idx++) {
			dp[idx][0] = min(dp[idx - 1][1] + costs[idx][0], dp[idx - 1][2] + costs[idx][0]);
			dp[idx][1] = min(dp[idx - 1][0] + costs[idx][1], dp[idx - 1][2] + costs[idx][1]);
			dp[idx][2] = min(dp[idx - 1][0] + costs[idx][2], dp[idx - 1][1] + costs[idx][2]);
		}
		if (k == 0) dp[N - 1][0] = 1000000;
		else if (k == 1) dp[N - 1][1] = 1000000;
		else dp[N - 1][2] = 1000000;
		int sub_minsum = min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
		minsum = minsum > sub_minsum ? sub_minsum : minsum;
	}

	cout << minsum;
}