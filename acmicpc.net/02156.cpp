#include <iostream>
#include <algorithm>
using namespace std;
int d[3][10001];
int DP(int n) {
	int * amount = new int[n + 1];//포도주 잔에 들어있는 양
	for (int i = 1; i <= n; i++) cin >> amount[i];
	d[1][1] = amount[1];
	d[2][1] = amount[1];
	d[0][2] = amount[1];
	d[1][2] = amount[2];
	d[2][2] = amount[1] + amount[2];
	for (int i = 3; i <= n; i++) {
		d[0][i] = max(d[0][i - 1], d[1][i - 1]);
		d[0][i] = max(d[0][i], d[2][i - 1]);
		d[1][i] = d[0][i - 1] + amount[i];
		d[2][i] = d[0][i - 2] + amount[i - 1] + amount[i];
	}
	int ret = max(d[0][n], d[1][n]);
	ret = max(ret, d[2][n]);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << DP(n);
	return 0;
}