#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];
int ans[1000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int sum = 0;
	ans[0] = arr[0];
	sum = ans[0];
	for (int i = 1; i < N; i++) {
		ans[i] = ans[i - 1] + arr[i];
		sum += ans[i];
	}
	cout << sum;
}