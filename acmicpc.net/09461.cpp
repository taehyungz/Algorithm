#include <iostream>
#include <vector>
using namespace std;

long long d[101];
long long DP(int num) {
	d[1] = 1; d[2] = 1; d[3] = 1; d[4] = 2; d[5] = 2;
	d[6] = 3; d[7] = 4;	d[8] = 5; d[9] = 7; d[10] = 9;
	for (int i = 11; i <= num; i++) {
		d[i] = d[i - 1] + d[i - 5];
	}
	return d[num];
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		cout << DP(num) << '\n';
	}
	return 0;
}