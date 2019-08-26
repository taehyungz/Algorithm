#include <iostream>
#include <cstdio>
using namespace std;
int arr[10001];
int main() {
	int N, temp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		arr[temp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] > 0) {
			while (arr[i]--) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}