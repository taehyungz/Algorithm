#include <iostream>
#include <utility>
using namespace std;
int main() {
	int N, M;//N�� ����, M�� ����
	cin >> N >> M;
	//2ĭ ��, 1ĭ ������ -> N:-2, M:+1
	//1ĭ ��, 2ĭ ������ -> N:-1, M:+2
	//1ĭ �Ʒ�, 2ĭ ������ -> N:+1, M:+2
	//2ĭ �Ʒ�, 1ĭ ������ -> N:+2, M:+1
	pair<int, int> n_pos = make_pair(N - 1, 0);//y,x
	bool check = false;//3������ �� �� �ִ��� üũ.
	bool checks[4] = { false, false, false, false };
	int count = 5;//4�� �̻� ������ ���

	int ymod = 2;
	int xmod = 1;
	int y_cond = -1;//���������� ������ 

	if (M < 5 && N>2) {
		cout << M;
		return 0;
	}
	else if (M < 7 && N>2) {
		cout << 4;
		return 0;
	}
	if (N == 1) {
		cout << 1;
		return 0;
	}
	else if (N == 2) {
		if (M <= 8) cout << (1 + M) / 2;
		else cout << 4;
		return 0;
	}
	//���ΰ� 4ĭ �̻��̿��� ��� ����� 1�� �̻� ����� ��
	n_pos.second = 6;
	while (n_pos.second < M - 1) {
		if (n_pos.first == 0) {
			y_cond *= -1;
		}
		else if (n_pos.first == N - 1 && n_pos.second != 0) {
			y_cond *= -1;
		}
		n_pos.first += y_cond * ymod;
		n_pos.second += 1;
		count++;
	}
	cout << count;
	return 0;
}