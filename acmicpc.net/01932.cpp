#include <iostream>
#include <algorithm>
using namespace std;
int d[501][501];
int DP(int N) {
	int ** triangle = new int*[N + 1];
	for (int i = 1; i <= N; i++) {
		triangle[i] = new int[i + 1];
		for (int j = 1; j <= i; j++) cin >> triangle[i][j];
	}
	d[1][1] = triangle[1][1];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) d[i][j] = d[i - 1][j] + triangle[i][j];
			else if (j == i) d[i][j] = d[i - 1][j - 1] + triangle[i][j];
			else d[i][j] = max(d[i - 1][j - 1] + triangle[i][j], d[i - 1][j] + triangle[i][j]);
		}
	}
	int max_sum = 0;
	for (int i = 1; i <= N; i++) {
		max_sum = max(max_sum, d[N][i]);
	}
	return max_sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}