#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	cout << (N - 1) * M + (M - 1); // �� ���� ��� �ڸ��µ� N-1��, �װ��� M��, M���� �ڸ��µ� M-1��
	return 0;
}