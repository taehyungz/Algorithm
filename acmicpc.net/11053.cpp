#include <iostream>
#include <algorithm>
using namespace std;
int d[1001];
int DP(int N) {
	int * numbers = new int[N];
	for (int i = 1; i <= N; i++) {
		cin >> numbers[i];
	}
	d[1] = 1;

	for (int i = 2; i <= N; i++) {
		int down_num = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (numbers[j] < numbers[i]) down_num = max(down_num, d[j]);
		}
		d[i] = down_num + 1;
	}
	int max_num = 0;
	for (int i = 1; i <= N; i++) max_num = max(max_num, d[i]);
	return max_num;
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}