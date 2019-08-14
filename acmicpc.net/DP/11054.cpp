#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void UDP(int N, vector<int> &ud, vector<int> &numbers) {
	for (int i = 0; i < N; i++) {
		ud[i] = 1;
		for (int j = 0; j < i; j++) {
			if (numbers[i] > numbers[j] && ud[i] < ud[j] + 1) ud[i] = ud[j] + 1;
		}
	}
}
int DP(int N) {
	//부분증가수열과 부분감소수열을 구한 후 더한 것 중 큰 값 구하기
	vector<int> numbers(N);
	vector<int> ud(N);//d[n]은 n+1자리의 수열중 가장 긴 증가수열의 길이
	vector<int> dd(N);//d[n]은 n+1자리의 수열중 가장 긴 감소수열의 길이
	for (int i = 0; i < N; i++) cin >> numbers[i];
	UDP(N, ud, numbers);
	reverse(numbers.begin(), numbers.end());//거꾸로 해서 구함(감소수열을 쉽게 구하기 위해서)
	UDP(N, dd, numbers);
	reverse(dd.begin(), dd.end());//거꾸로 해서 구했으므로 원래대로 돌림
	int max_num = 0;
	int check = 0;
	for (int i = 0; i < N; i++) {
		if (max_num < ud[i] + dd[i]) {
			max_num = ud[i] + dd[i];
			check = i;
		}
	}
	return ud[check] + dd[check] - 1;//check번째는 2번 더했으므로 1을 뺌
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}