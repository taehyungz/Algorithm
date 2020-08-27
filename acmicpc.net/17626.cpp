#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[50001];
int main(int argc, char* argv[])
{
	int n;
	int min_num;
	vector<int> vc;

	cin >> n;
	dp[1] = 1;

	int sqrtn = sqrt(n) + 1;

	for (int i = 1; i <= sqrtn; ++i) {
		vc.push_back(i * i);
	}

	for (int i = 2; i <= n; i++) {
		min_num = 3;
		for (int j = 0; vc[j] <= i; j++) {
			int tmp = i - vc[j];
			min_num = min(min_num, dp[tmp]);
		}
		dp[i] = min_num + 1;
	}
	cout << dp[n] << endl;
	return 0;
}