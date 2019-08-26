#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
queue<int> q;//vc에서 각 정점에 대해 이어져 있는 정점들을 큐에 저장
vector<int> vc[100001];//입력에 대해서 이어진 두 정점을 기록
bool check[100001];//큐에 저장하기 위해 BFS탐색을 할 때 방문여부를 저장
int parents[100001];//각 정점들에 대해 부모노드를 저장
void BFS(int n) {
	q.push(n);
	while (!q.empty()) {
		int V = q.front();
		check[V] = true;
		q.pop();
		for (int i = 0; i < vc[V].size(); i++) {
			int nextV = vc[V][i];
			if (check[nextV] == true) continue;
			parents[nextV] = V;
			q.push(nextV);
			check[nextV] = true;
		}
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	BFS(1);
	for (int i = 2; i < N + 1; i++) {
		cout << parents[i] << '\n';
	}
	return 0;
}