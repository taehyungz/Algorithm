#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int map[100][100];
bool check[100][100];
int num[100][100];
int N, M;
queue<pair<int, int>> q;
void BFS(int y, int x) {
	q.push(make_pair(x, y));
	num[0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y > 0 && map[y - 1][x] && !check[y - 1][x]) {//À§Ä­
			q.push(make_pair(y - 1, x));
			check[y - 1][x] = true;
			num[y - 1][x] = num[y][x] + 1;//´ÙÀ½Ä­ÀÇ È½¼ö = ÇöÀçÄ­ÀÇ È½¼ö+1
		}
		if (x > 0 && map[y][x - 1] && !check[y][x - 1]) {//¿ŞÂÊÄ­
			q.push(make_pair(y, x - 1));
			check[y][x - 1] = true;
			num[y][x - 1] = num[y][x] + 1;
		}
		if (x < M - 1 && map[y][x + 1] && !check[y][x + 1]) {//¿À¸¥ÂÊÄ­
			q.push(make_pair(y, x + 1));
			check[y][x + 1] = true;
			num[y][x + 1] = num[y][x] + 1;
		}
		if (y < N - 1 && map[y + 1][x] && !check[y + 1][x]) {//¾Æ·¡Ä­
			q.push(make_pair(y + 1, x));
			check[y + 1][x] = true;
			num[y + 1][x] = num[y][x] + 1;
		}
		if (x == M - 1 && y == N - 1) {
			cout << num[y][x] << '\n';
			return;
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);//Áöµµ ÀÔ·Â
		}
	}
	BFS(0, 0);
	return 0;
}