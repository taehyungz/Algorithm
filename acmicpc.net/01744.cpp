#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vc;
int main() {
	int N;
	int temp;
	int minuscnt = 0;
	int zerocnt = 0;
	int pluscnt = 0;
	int sum = 0;
	int onecnt = 0;
	cin >> N;
	while (N--) {
		cin >> temp;
		vc.push_back(temp);
		if (temp > 1) pluscnt++;
		else if (temp == 1) onecnt++;
		else if (temp == 0) zerocnt++;
		else minuscnt++;
	}
	sort(vc.begin(), vc.end());
	for (int i = 0; i < minuscnt - 1; i += 2) { //���̳ʽ� �κ� ���
		sum = sum + (vc[i] * vc[i + 1]);
	}
	if (minuscnt % 2 == 1 && zerocnt == 0) { //���̳ʽ��� Ȧ�����̰�, 0�� ������ ���̳ʽ� ����x
		sum += vc[minuscnt - 1];
	}
	if (onecnt > 0) {
		sum += onecnt;
	}
	for (int i = minuscnt + zerocnt + onecnt; i < vc.size(); i += 2) {
		if (pluscnt % 2 == 1 && i == minuscnt + zerocnt + onecnt) {
			sum += vc[i];
			i--;//i�� 2�� �����ֹǷ�
			continue;
		}
		else {
			sum = sum + vc[i] * vc[i + 1];
		}
	}
	cout << sum;
	return 0;
}