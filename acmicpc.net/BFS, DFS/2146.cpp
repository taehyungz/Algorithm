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
int ud[] = { 0,1,-1,0 };//좌,하,상,우
queue<pair<int, int>> q;
void BFS(const int &i, const int &j, const int &land_num) {//i는 세로, j는 가로
	//각 섬들에 번호 매기기
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
		for (int i = 0; i < 4; i++) {//섬 한 칸씩 넓히면서 거리 측정
			int x = nowx + rl[i];
			int y = nowy + ud[i];
			if (x<0 || y<0 || x>N - 1 || y>N - 1) continue;
			if (check[y][x] != 0) continue;
			dis[y][x] = dis[nowy][nowx] + 1;
			check[y][x] = check[nowy][nowx];
			q.push(make_pair(y, x));
		}
		for (int i = 0; i < 4; i++) {//섬과 섬이 만났으면 거리 출력
			//위의 포문과 합쳐서 구한후 return하지 않고 따로 구하는 이유는 큐에 먼저 넣어진 A섬이 B섬과 만나는 것이
			//B섬과 C섬이 만나는 것보다 먼저 이루어질 수 있는데, 거리는 B와 C섬이 더 가까울 수 있기 때문이다.
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
		fill(&dis[i][0], &dis[i][N], -1);//거리배열의 각 칸들을 -1초기화
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (land[i][j] == 1) {
				dis[i][j] = 0;//육지면 0으로 초기화
				q.push(make_pair(i, j));
			}
		}
	}
	Make_land();
	return 0;
}