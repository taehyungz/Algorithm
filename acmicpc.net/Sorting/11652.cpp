#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long arr[1000000];

int main() {
	int N ;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + N);
	int ans_cnt = 1;
	int cnt = 1;
	int ans = 0;
	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i - 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}
		if (ans_cnt < cnt) {
			ans_cnt = cnt;
			ans = i;
		}
	}
	printf("%lld", arr[ans]);
	return 0;
}