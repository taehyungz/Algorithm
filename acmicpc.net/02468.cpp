#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int arr[101][101];
bool visit[101][101];
int maxarea;
int maxnum;
queue<pair<int, int>> q;

void BFS(int N, int x, int y, int rain) {
	q.push(make_pair(y, x));
	visit[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (y - 1 >= 0 && arr[y - 1][x] > rain && !visit[y - 1][x]) {
			q.push(make_pair(y - 1, x));
			visit[y - 1][x] = true;
		}
		if (y + 1 < N && arr[y + 1][x] > rain && !visit[y + 1][x]) {
			q.push(make_pair(y + 1, x));
			visit[y + 1][x] = true;
		}
		if (x - 1 >= 0 && arr[y][x - 1] > rain && !visit[y][x - 1]) {
			q.push(make_pair(y, x - 1));
			visit[y][x - 1] = true;
		}
		if (x + 1 < N && arr[y][x + 1] > rain && !visit[y][x + 1]) {
			q.push(make_pair(y, x + 1));
			visit[y][x + 1] = true;
		}
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			maxnum = maxnum > arr[i][j] ? maxnum : arr[i][j];
		}
	}
	for (int rain = 0; rain <= maxnum; rain++) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[j][i] > rain && !visit[j][i]) {
					BFS(N, i, j, rain);
					count++;
				}
			}
		}
		maxarea = maxarea > count ? maxarea : count;
		memset(visit, 0, sizeof(visit));
	}
	cout << maxarea;
}