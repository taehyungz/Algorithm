#include <iostream>
using namespace std;
bool check[5001];
int main() {
	int N, K;
	cin >> N >> K;
	cout << "<";
	int number_cnt = 0;
	int idx = 0;
	int k_cnt = 0;
	while (number_cnt < N) {
		k_cnt = 0;
		while (k_cnt < K) {
			idx++;
			if (idx > N) idx -= N;
			if (!check[idx]) {
				k_cnt++;
			}
		}
		check[idx] = true;
		cout << idx;
		number_cnt++;
		if (number_cnt != N) cout << ", ";
	}
	cout << ">";
	return 0;
}