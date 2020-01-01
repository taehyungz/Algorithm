#include <iostream>
using namespace std;
int coins[11];
int main() {
	int N, K;
	int num = 0;//동전 개수
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}
	while (K != 0) {//0이 될 때까지 반복
		for (int i = N - 1; i >= 0; i--) {
			if (coins[i] > K) continue;//동전의 단위가 더 크면 continue
			else if (coins[i] == K) {//동전의 단위와 돈이 같을 때
				num++;
				K -= coins[i];
			}
			else {//돈이 더 클때
				while (K >= coins[i]) {//돈이 작아질 때까지 동전의 수를 계속 증가
					K -= coins[i];
					num++;
				}
			}
		}
	}
	cout << num;
	return 0;
}