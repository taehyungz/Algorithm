#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K, cnt;
	cin >> N >> K;
	cnt = N - K;
	vector<int> vc;
	vector<int> ans;
	int temp;
	scanf("%1d", &temp);
	vc.push_back(temp);
	for (int i = 1; i < N; i++) {
		scanf("%1d", &temp);
		while (K && vc.size() > 0 && vc.back() < temp) {
			//������ �� ���� �����ְ�, ���� ���� ������, ���� ���� ���� ������ ������ ���� ���� ����� ���� ���� ����
			vc.pop_back();
			K--;
		}
		vc.push_back(temp);
	}
	for (int i = 0; i < cnt; i++) {
		cout << vc[i];
	}
}