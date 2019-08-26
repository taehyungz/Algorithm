#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int DP(int N) {
	vector<int> d(N);//d[i]�� i+1 ������ �������� i+1��° ���� ������ �������� ���� ū ���� ����
	vector<int> numbers(N);
	for (int i = 0; i < N; i++) cin >> numbers[i];
	d[0] = numbers[0];
	for (int i = 1; i < N; i++) {
		d[i] = numbers[i];
		if (d[i] < d[i - 1] + numbers[i]) d[i] = d[i - 1] + numbers[i];//�������̹Ƿ� �տ��� �˻��Ѵ�
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