#include <iostream>
#include <cstdio>
using namespace std;

int students[100001];
int check[100001];
int which_team[100001];

int DFS(int x, int cnt, int &step) {
	if (check[x] != 0) {
		if (step != which_team[x]) {
			return 0;
		}
		return cnt - check[x];
		//����Ŭ�� ��� ��(�߰����� ����Ŭ�� ��� ����Ŭ ������
		//�л����� �� ���� �ƴϴ�. �� ���� �л����� ���� ������
	}
	check[x] = cnt;
	which_team[x] = step;
	return DFS(students[x], cnt + 1, step);
}
int main() {
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &students[i]);
			check[i] = 0;
			which_team[i] = 0;
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (check[i] == 0) {
				ans += DFS(i, 1, i);
			}
		}
		printf("%d\n", N - ans);//��ü �л������� ���� ���Ե� �л����� ��
	}
}