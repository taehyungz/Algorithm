#include <iostream>
using namespace std;

int main() {
	int W, M, K;//W�� ���л�, M�� ���л�, K�� ���Ͻ� ���� �ο�
	int team = 0;
	cin >> W >> M >> K;
	while (K--) {
		//W=M*2�̸� ������ ������ ����
		if (W > 2 * M) {
			W--;
		}
		else {
			M--;
		}
	}
	while (M >= 1 && W >= 2) {
		M -= 1;
		W -= 2;
		team++;
	}
	cout << team;
	return 0;
}