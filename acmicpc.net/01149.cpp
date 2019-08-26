#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][3];
int DP(int N) {
	int *rcost = new int[N + 1];
	int *bcost = new int[N + 1];
	int *gcost = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> rcost[i];
		cin >> gcost[i];
		cin >> bcost[i];
	}
	d[0][0] = 0;
	d[0][1] = 0;
	d[0][2] = 0;
	d[1][0] = rcost[1];
	d[1][1] = gcost[1];
	d[1][2] = bcost[1];
	for (int i = 2; i <= N; i++) {
		d[i][0] = min(d[i - 1][1] + rcost[i], d[i - 1][2] + rcost[i]);
		d[i][1] = min(d[i - 1][0] + gcost[i], d[i - 1][2] + gcost[i]);
		d[i][2] = min(d[i - 1][0] + bcost[i], d[i - 1][1] + bcost[i]);
	}
	int min_cost = min(d[N][0], d[N][1]);
	return min(min_cost, d[N][2]);
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}