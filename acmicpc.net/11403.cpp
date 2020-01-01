#include <iostream>
#define MAX 1000000
using namespace std;

void Floyd(int(*arr)[101], int N) {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] < MAX) {
				cout << 1 << ' ';
			}
			else cout << 0 << ' ';
		}
		cout << '\n';
	}
	return;
}
int main() {
	int N;
	cin >> N;
	int arr[101][101];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) arr[i][j] = MAX;
		}
	}
	Floyd(arr, N);
	return 0;
}