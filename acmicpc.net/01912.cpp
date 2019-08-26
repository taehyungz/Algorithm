#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int DP(int N) {
	vector<int> d(N);//d[i]는 i+1 길이의 수열에서 i+1번째 수를 포함한 연속합이 가장 큰 값을 저장
	vector<int> numbers(N);
	for (int i = 0; i < N; i++) cin >> numbers[i];
	d[0] = numbers[0];
	for (int i = 1; i < N; i++) {
		d[i] = numbers[i];
		if (d[i] < d[i - 1] + numbers[i]) d[i] = d[i - 1] + numbers[i];//연속합이므로 앞에만 검사한다
	}
	return *max_element(d.begin(), d.end());
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}