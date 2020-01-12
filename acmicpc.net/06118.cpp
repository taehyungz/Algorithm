//6118¹ø
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int> vc[20001];
int visited[20001];
queue<pair<int, int>> q;
void BFS(int from) {
	q.push(make_pair(from, 0));
	visited[from] = 99999;
	int count;
	while (!q.empty()) {
		from = q.front().first;
		count = q.front().second;
		q.pop();
		for (int i = 0; i < vc[from].size(); i++) {
			if (visited[vc[from][i]] == 0) {
				q.push(make_pair(vc[from][i], count + 1));
				visited[vc[from][i]] = count + 1;
			}
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	BFS(1);
	int max = 0;
	vector<int> list;
	for (int i = 2; i <= N; i++) {
		if (visited[i] > max) {
			max = visited[i];
			list.clear();
			list.push_back(i);
		}
		else if (visited[i] == max) {
			list.push_back(i);
		}
	}
	cout << list[0] << ' ' << visited[list[0]] << ' ' << list.size();
	return 0;
}