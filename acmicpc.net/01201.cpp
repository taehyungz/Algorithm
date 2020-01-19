#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vc;
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	//�ִ�κ����������� �ִ�κа��Ҽ��� -> ���ڸ������ ����⿡�� �� ���� ������
	if (M + K - 1 <= N && N <= M * K) {//N���� ���� ����� ���ؼ� ��� M+K-1�� ���ų� Ŀ����
		//N�� M*K���� ũ�� ��ѱ��� ������ ���� ���� �� ����
		for (int i = 1; i <= N; i++) {
			vc.push_back(i);
		}
		int idx = 0;//�� �׷��� ���� �ε���
		for (int i = 1; i <= M; i++) { //M���� �׷�
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