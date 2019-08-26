#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;

bool check[50][50];
int map[50][50];
int w, h;
int land;
pair<int, int> pos[8];
void DFS(int &i, int &j, int level) {
	if (level == 1) land++;//ó������ ���� ������ ������Ŵ(������ ����Լ��� ���� ���̴�)
	check[i][j] = true;
	for (int k = 0; k < 8; k++) {
		int y = i + pos[k].first;
		int x = j + pos[k].second;
		if (x < 0 || y < 0 || x >= w || y >= h || map[y][x] == 0 || check[y][x] == true) continue;
		DFS(y, x, level + 1);
	}
}
int main() {
	int cnt = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i != 0 || j != 0) {
				pos[cnt++] = make_pair(i, j);//��ġ �� �����
			}
		}
	}
	do {
		scanf("%d %d", &w, &h);
		land = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);//�� ���� �Է�
				check[i][j] = false;//Ȯ�� �ߴ��� üũ�ϴ� �迭 �ʱ�ȭ
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && check[i][j] == false) {
					DFS(i, j, 1);//�����ε� ���� �湮 �� �� ��� DFS ����
				}
			}
		}
		if (w != 0 && h != 0) printf("%d\n", land);
	} while (w != 0 && h != 0);
}