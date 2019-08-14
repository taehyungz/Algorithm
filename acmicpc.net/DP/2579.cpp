#include <iostream>
#include <algorithm>
using namespace std;
int d[300][3];
int DP(int N) {
	int * score = new int[N + 1];
	for (int i = 1; i <= N; i++) cin >> score[i];
	d[1][0] = 0;
	d[1][1] = score[1];
	d[1][2] = score[1];
	d[2][0] = score[1];
	d[2][1] = score[2];
	d[2][2] = score[1] + score[2];
	for (int i = 3; i <= N; i++) {
		d[i][0] = max(d[i - 1][1], d[i - 1][2]);
		d[i][1] = max(d[i - 2][1] + score[i], d[i - 2][2] + score[i]);
		d[i][2] = d[i - 1][1] + score[i];
	}
	return max(d[N][1], d[N][2]);
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}