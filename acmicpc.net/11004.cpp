#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int arr[5000000];
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	nth_element(arr, arr + K - 1, arr + N);
	printf("%d\n", arr[K - 1]);
	return 0;
}