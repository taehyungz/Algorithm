#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int DP(int N) {
	//큰 제곱수들을 빼면서, 뺀 수가 d에 있으면 이용하기
	vector<int> d(N + 1);//d[i]는 제곱수의 합으로 표현할 때 최소항의 항의 개수 
	for (int i = 1; i <= N; i++) {
		d[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (d[i] > d[i - j * j] + 1) d[i] = d[i - j * j] + 1;
		}
	}
	return d[N];
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}