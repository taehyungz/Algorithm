#include <iostream>
#include <queue>
using namespace std;

void BFS(const int &N, const int &K, queue<pair<int, int>> q, bool check[]) {
	q.push(make_pair(N, 0));
	while (!q.empty()) {
		int now_pos = q.front().first;
		int now_count = q.front().second;
		q.pop();
		check[now_pos] = true;
		if (now_pos == K) {
			cout << now_count;
			return;
		}
		if (now_pos + 1 <= 100000 && check[now_pos + 1] != true) q.push(make_pair(now_pos + 1, now_count + 1));
		if (now_pos - 1 >= 0 && check[now_pos - 1] != true) q.push(make_pair(now_pos - 1, now_count + 1));
		if (now_pos * 2 <= 100000 && check[now_pos * 2] != true) q.push(make_pair(now_pos * 2, now_count + 1));
	}
}
int main() {
	int N, K;
	cin >> N >> K;
	bool check[100001];
	for (int i = 0; i < 100001; i++) {
		check[i] = false;//check배열에 대한 초기화가 필요하다(안 할 시 틀림)
	}
	queue<pair<int, int>> q;
	BFS(N, K, q, check);
	return 0;
}