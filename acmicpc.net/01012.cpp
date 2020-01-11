#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int arr[50][50];
bool visit[50][50];

void BFS(int x, int y, int M, int N, int K) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (y - 1 >= 0 && !visit[y - 1][x] && arr[y - 1][x] == 1) {
			q.push(make_pair(y - 1, x));
			visit[y - 1][x] = true;
		}
		if (y + 1 < N && !visit[y + 1][x] && arr[y + 1][x] == 1) {
			q.push(make_pair(y + 1, x));
			visit[y + 1][x] = true;
		}
		if (x - 1 >= 0 && !visit[y][x - 1] && arr[y][x - 1] == 1) {
			q.push(make_pair(y, x - 1));
			visit[y][x - 1] = true;
		}
		if (x + 1 < M && !visit[y][x + 1] && arr[y][x + 1] == 1) {
			q.push(make_pair(y, x + 1));
			visit[y][x + 1] = true;
		}
	}
}
int main() {
	int T;
	cin >> T;
	int M, N, K;
	int x, y;
	int count = 0;
	while (T--) {
		count = 0;
		cin >> M >> N >> K;
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		while (K--) {
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[j][i] == 1 && !visit[j][i]) {
					BFS(i, j, M, N, K);
					count++;
				}
			}
		}
		cout << count << '\n';
	}
}