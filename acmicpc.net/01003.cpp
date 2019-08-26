#include <iostream>
using namespace std;
int d[41][2];
void DP(int num) {
	d[0][0] = 1;
	d[0][1] = 0;
	d[1][0] = 0;
	d[1][1] = 1;
	for (int i = 2; i <= num; i++) {
		d[i][0] = d[i - 1][0] + d[i - 2][0];
		d[i][1] = d[i - 1][1] + d[i - 2][1];
	}
	cout << d[num][0] << " " << d[num][1] << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		DP(num);
	}
	return 0;
}