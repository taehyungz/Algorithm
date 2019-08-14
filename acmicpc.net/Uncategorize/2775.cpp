#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	int arr[15][15];
	for (int i = 0; i < T; i++) {
		int k, n;
		cin >> k >> n;
		for (int i = 1; i <= n; i++) {
			arr[0][i] = i;
		}
		//k층의 n호에는 몇 명이 살고 있는가?
		//k층의 n호에 살려면 k-1층의 1호부터 n호까지의 사람들의 합만큼이 살아야 함
		for (int j = 1; j <= k; j++) {
			for (int m = 1; m <= n; m++) {
				int sum = 0;
				for (int s = 1; s <= m; s++) {
					sum += arr[j - 1][s];
				}
				arr[j][m] = sum;
			}
		}
		cout << arr[k][n] << '\n';
	}
	return 0;
}