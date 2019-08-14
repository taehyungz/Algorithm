#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int DP(int N) {
	//ū ���������� ���鼭, �� ���� d�� ������ �̿��ϱ�
	vector<int> d(N + 1);//d[i]�� �������� ������ ǥ���� �� �ּ����� ���� ���� 
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