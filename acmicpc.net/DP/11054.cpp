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
	//�κ����������� �κа��Ҽ����� ���� �� ���� �� �� ū �� ���ϱ�
	vector<int> numbers(N);
	vector<int> ud(N);//d[n]�� n+1�ڸ��� ������ ���� �� ���������� ����
	vector<int> dd(N);//d[n]�� n+1�ڸ��� ������ ���� �� ���Ҽ����� ����
	for (int i = 0; i < N; i++) cin >> numbers[i];
	UDP(N, ud, numbers);
	reverse(numbers.begin(), numbers.end());//�Ųٷ� �ؼ� ����(���Ҽ����� ���� ���ϱ� ���ؼ�)
	UDP(N, dd, numbers);
	reverse(dd.begin(), dd.end());//�Ųٷ� �ؼ� �������Ƿ� ������� ����
	int max_num = 0;
	int check = 0;
	for (int i = 0; i < N; i++) {
		if (max_num < ud[i] + dd[i]) {
			max_num = ud[i] + dd[i];
			check = i;
		}
	}
	return ud[check] + dd[check] - 1;//check��°�� 2�� �������Ƿ� 1�� ��
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << DP(N);
	return 0;
}