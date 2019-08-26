#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int DP(int N) {
	vector<int> numbers(N);
	vector<int> d(N, 1);
	for (int i = 0; i < N; i++) cin >> numbers[i];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++)
			if (numbers[i] < numbers[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
	}
	int ret = *max_element(d.begin(), d.end());
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}