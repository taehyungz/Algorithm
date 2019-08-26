#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
int box[1000][1000];//토마토 보관 박스
int check[1000][1000] = { -1 };//썩은 날짜 기록
queue<pair<int, int>> q;//BFS 위치 저장
int M, N;
pair<int, int> pair_arr[4] = { make_pair(0,1), make_pair(1,0),
							make_pair(-1,0), make_pair(0,-1) };
void BFS() {
	int height, width;
	while (!q.empty()) {
		height = q.front().first;
		width = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {//우/하/상/좌
			int y = height + pair_arr[i].first;
			int x = width + pair_arr[i].second;
			if (y<0 || x<0 || y>N - 1 || x>M - 1) continue;
			if (check[y][x] != -1) continue;
			if (box[y][x] == 0) {
				check[y][x] = check[height][width] + 1;
				q.push(make_pair(y, x));
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == -1 && box[i][j] != -1) {
				printf("-1");
				return;
			}
		}
	}
	printf("%d", check[height][width]);
	return;
}
int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = -1;
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = 0;
			}
		}
	}
	if (q.empty()) {
		printf("0\n");
		return 0;
	}
	BFS();
}