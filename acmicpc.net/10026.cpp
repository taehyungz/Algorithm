#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int arr[100][100];
bool visit[100][100];
queue<pair<int, int>> q;
void BFS(int N, int y, int x) {//정상
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();
		visit[now_y][now_x] = true;
		if (now_y - 1 >= 0 && visit[now_y - 1][now_x] != true && arr[now_y][now_x] == arr[now_y - 1][now_x]) {
			q.push(make_pair(now_y - 1, now_x));
			visit[now_y - 1][now_x] = true;
		}
		if (now_y + 1 < N && visit[now_y + 1][now_x] != true && arr[now_y][now_x] == arr[now_y + 1][now_x]) {
			q.push(make_pair(now_y + 1, now_x));
			visit[now_y + 1][now_x] = true;
		}
		if (now_x - 1 >= 0 && visit[now_y][now_x - 1] != true && arr[now_y][now_x] == arr[now_y][now_x - 1]) {
			q.push(make_pair(now_y, now_x - 1));
			visit[now_y][now_x - 1] = true;
		}
		if (now_x + 1 < N && visit[now_y][now_x + 1] != true && arr[now_y][now_x] == arr[now_y][now_x + 1]) {
			q.push(make_pair(now_y, now_x + 1));
			visit[now_y][now_x + 1] = true;
		}
	}
}
void BFS2(int N, int y, int x) {//적록
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();
		visit[now_y][now_x] = true;
		if (now_y - 1 >= 0 && visit[now_y - 1][now_x] != true && abs(arr[now_y][now_x] - arr[now_y - 1][now_x]) < 2) {
			q.push(make_pair(now_y - 1, now_x));
			visit[now_y - 1][now_x] = true;
		}
		if (now_y + 1 < N && visit[now_y + 1][now_x] != true && abs(arr[now_y][now_x] - arr[now_y + 1][now_x]) < 2) {
			q.push(make_pair(now_y + 1, now_x));
			visit[now_y + 1][now_x] = true;
		}
		if (now_x - 1 >= 0 && visit[now_y][now_x - 1] != true && abs(arr[now_y][now_x] - arr[now_y][now_x - 1]) < 2) {
			q.push(make_pair(now_y, now_x - 1));
			visit[now_y][now_x - 1] = true;
		}
		if (now_x + 1 < N && visit[now_y][now_x + 1] != true && abs(arr[now_y][now_x] - arr[now_y][now_x + 1]) < 2) {
			q.push(make_pair(now_y, now_x + 1));
			visit[now_y][now_x + 1] = true;
		}
	}
}
int main() {
	int N;
	char temp;
	int count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			switch (temp) {//적록색맹의 경우를 구할 때 차를 이용하기 위해 1,2,4로 설정
			case 'R':
				arr[i][j] = 1;
				break;
			case 'G':
				arr[i][j] = 2;
				break;
			case 'B':
				arr[i][j] = 4;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] != true) {
				BFS(N, i, j);
				count++;
			}
		}
	}
	cout << count << ' ';
	count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] != true) {
				BFS2(N, i, j);
				count++;
			}
		}
	}
	cout << count;
	return 0;
}