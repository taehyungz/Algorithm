#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[100][100];
bool check[100][100];
vector<int> vc;
queue<pair<int, int>> q;

void BFS(int y, int x, int N, int M) {
	q.push(make_pair(y, x));
	int area = 0;
	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();
		area++;
		visit[now_y][now_x] = true;
		if (now_y - 1 >= 0 && !visit[now_y - 1][now_x] && !check[now_y - 1][now_x]) {
			q.push(make_pair(now_y - 1, now_x));
			visit[now_y - 1][now_x] = true;
		}
		if (now_y + 1 < M && !visit[now_y + 1][now_x] && !check[now_y + 1][now_x]) {
			q.push(make_pair(now_y + 1, now_x));
			visit[now_y + 1][now_x] = true;
		}
		if (now_x - 1 >= 0 && !visit[now_y][now_x - 1] && !check[now_y][now_x - 1]) {
			q.push(make_pair(now_y, now_x - 1));
			visit[now_y][now_x - 1] = true;
		}
		if (now_x + 1 < N && !visit[now_y][now_x + 1] && !check[now_y][now_x + 1]) {
			q.push(make_pair(now_y, now_x + 1));
			visit[now_y][now_x + 1] = true;
		}
	}
	vc.push_back(area);
}
int main() {
	int M, N, K;
	cin >> M >> N >> K;
	//N->x, M->y
	while (K--) {
		int a, b;
		cin >> a >> b;
		pair<int, int> point1 = make_pair(b, a);//y,x
		cin >> a >> b;
		pair<int, int> point2 = make_pair(b, a);//y,x
		int maxx = point1.second > point2.second ? point1.second : point2.second;
		int minx = point1.second < point2.second ? point1.second : point2.second;
		int maxy = point1.first > point2.first ? point1.first : point2.first;
		int miny = point1.first < point2.first ? point1.first : point2.first;
		for (int x = minx; x < maxx; x++) {
			for (int y = miny; y < maxy; y++) {
				check[y][x] = true;
			}
		}
	}
	int count = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (!visit[y][x] && !check[y][x]) {
				BFS(y, x, N, M);
				count++;
			}
		}
	}
	cout << count << ' ';
	sort(vc.begin(), vc.end());
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << ' ';
	}
}