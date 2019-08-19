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
	if (level == 1) land++;//처음에만 땅의 개수를 증가시킴(이후의 재귀함수는 같은 땅이다)
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
				pos[cnt++] = make_pair(i, j);//위치 쌍 만들기
			}
		}
	}
	do {
		scanf("%d %d", &w, &h);
		land = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);//맵 정보 입력
				check[i][j] = false;//확인 했는지 체크하는 배열 초기화
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && check[i][j] == false) {
					DFS(i, j, 1);//육지인데 아직 방문 안 한 경우 DFS 실행
				}
			}
		}
		if (w != 0 && h != 0) printf("%d\n", land);
	} while (w != 0 && h != 0);
}