#include <iostream>
#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int land[100][100];
int check[100][100];
int dis[100][100];
int N;
int rl[] = { -1,0,0,1 };
int ud[] = { 0,1,-1,0 };//��,��,��,��
queue<pair<int, int>> q;
void BFS(const int &i, const int &j, const int &land_num) {//i�� ����, j�� ����
	//�� ���鿡 ��ȣ �ű��
	q.push(make_pair(i, j));
	while (!q.empty()) {
		check[i][j] = land_num;
		int nowx = q.front().second;
		int nowy = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = nowx + rl[i];
			int y = nowy + ud[i];
			if (y<0 || x<0 || y>N - 1 || x>N - 1) continue;
			if (check[y][x] == 0 && land[y][x] == 1) {
				check[y][x] = land_num;
				q.push(make_pair(y, x));
			}
		}
	}
}
void Make_land() {
	int ans = -1;
	while (!q.empty()) {
		int nowx = q.front().second;
		int nowy = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {//�� �� ĭ�� �����鼭 �Ÿ� ����
			int x = nowx + rl[i];
			int y = nowy + ud[i];
			if (x<0 || y<0 || x>N - 1 || y>N - 1) continue;
			if (check[y][x] != 0) continue;
			dis[y][x] = dis[nowy][nowx] + 1;
			check[y][x] = check[nowy][nowx];
			q.push(make_pair(y, x));
		}
		for (int i = 0; i < 4; i++) {//���� ���� �������� �Ÿ� ���
			//���� ������ ���ļ� ������ return���� �ʰ� ���� ���ϴ� ������ ť�� ���� �־��� A���� B���� ������ ����
			//B���� C���� ������ �ͺ��� ���� �̷���� �� �ִµ�, �Ÿ��� B�� C���� �� ����� �� �ֱ� �����̴�.
			int x = nowx + rl[i];
			int y = nowy + ud[i];
			if (x<0 || y<0 || x>N - 1 || y>N - 1) continue;
			if (check[nowy][nowx] != check[y][x]) {
				int newlength = dis[y][x] + dis[nowy][nowx];
				if (ans == -1) ans = newlength;
				ans = ans < newlength ? ans : newlength;
			}
		}
	}
	printf("%d", ans);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &land[i][j]);
		}
	}
	int land_num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0 && land[i][j] == 1) {
				BFS(i, j, land_num++);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		fill(&dis[i][0], &dis[i][N], -1);//�Ÿ��迭�� �� ĭ���� -1�ʱ�ȭ
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (land[i][j] == 1) {
				dis[i][j] = 0;//������ 0���� �ʱ�ȭ
				q.push(make_pair(i, j));
			}
		}
	}
	Make_land();
	return 0;
}