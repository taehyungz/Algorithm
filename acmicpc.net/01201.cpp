#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vc;
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	//최대부분증가수열과 최대부분감소수열 -> ㅅ자모양으로 꼭대기에서 한 수를 공유함
	if (M + K - 1 <= N && N <= M * K) {//N개의 수로 만들기 위해선 적어도 M+K-1과 같거나 커야함
		//N이 M*K보다 크면 비둘기집 원리에 의해 만들 수 없다
		for (int i = 1; i <= N; i++) {
			vc.push_back(i);
		}
		int idx = 0;//각 그룹의 시작 인덱스
		for (int i = 1; i <= M; i++) { //M개의 그룹
			int temp = min(idx + K, N - M + i);
			reverse(vc.begin() + idx, vc.begin() + temp);
			idx = temp;
		}
		for (int i = 0; i < N; i++) {
			cout << vc[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
	return 0;
}