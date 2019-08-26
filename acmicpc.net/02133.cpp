#include <iostream>
#include <vector>
using namespace std;
int DP(int N) {
	vector<int> d(N + 1);
	d[0] = 1;
	for (int i = 2; i <= N; i += 2) {
		for (int j = 1; j * 2 <= i; j++) {
			if (j == 1) d[i] = d[i] + 3 * d[i - j * 2];
			else d[i] = d[i] + 2 * d[i - j * 2];
		}
	}
	return d[N];
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}