#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int check[25][25];//�湮 �ߴ��� �� �ߴ��� üũ
string str[25];
int N;
vector<int> vc;

void DFS(int i, int j, const int &dong) {
	check[i][j] = dong;
	if (i > 0 && str[i - 1][j] == '1' && check[i - 1][j] == 0) {//����
		DFS(i - 1, j, dong);
	}
	if (i < N - 1 && str[i + 1][j] == '1' && check[i + 1][j] == 0) {//�Ʒ���
		DFS(i + 1, j, dong);
	}
	if (j > 0 && str[i][j - 1] == '1' && check[i][j - 1] == 0) {//����
		DFS(i, j - 1, dong);
	}
	if (j < N - 1 && str[i][j + 1] == '1' && check[i][j + 1] == 0) {//������
		DFS(i, j + 1, dong);
	}
	vc[dong]++;//���� �� ����
}
int main() {
	int dong = 1;//check�迭�� 0���� �ʱ�ȭ�Ǿ� �����Ƿ� 1���� ����
	cin >> N;
	vc.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (str[i][j] == '1' && check[i][j] == 0) {
				vc.push_back(0);
				DFS(i, j, dong);
				dong++;
			}
		}
	}
	sort(vc.begin(), vc.end());
	cout << vc.size() - 1 << '\n';
	for (int i = 1; i < vc.size(); i++) {
		cout << vc[i] << '\n';
	}
}