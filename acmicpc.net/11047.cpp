#include <iostream>
using namespace std;
int coins[11];
int main() {
	int N, K;
	int num = 0;//���� ����
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}
	while (K != 0) {//0�� �� ������ �ݺ�
		for (int i = N - 1; i >= 0; i--) {
			if (coins[i] > K) continue;//������ ������ �� ũ�� continue
			else if (coins[i] == K) {//������ ������ ���� ���� ��
				num++;
				K -= coins[i];
			}
			else {//���� �� Ŭ��
				while (K >= coins[i]) {//���� �۾��� ������ ������ ���� ��� ����
					K -= coins[i];
					num++;
				}
			}
		}
	}
	cout << num;
	return 0;
}