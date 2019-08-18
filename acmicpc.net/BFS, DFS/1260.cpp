#include <cstdio>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, V;
bool checkDFS[1001];
bool checkBFS[1001];
vector<int> *vc;
void DFS(int startV) {
	checkDFS[startV] = true;
	printf("%d ", startV);
	for (int i = 0; i < vc[startV].size(); i++) {
		if (checkDFS[vc[startV][i]] == false) {
			DFS(vc[startV][i]);
		}
	}
}
void BFS(int startV) {
	queue<int> queue;
	queue.push(startV);
	checkBFS[startV] = true;
	while (!queue.empty()) {
		startV = queue.front();
		queue.pop();
		printf("%d ", startV);
		for (int i = 0; i < vc[startV].size(); i++) {
			if (checkBFS[vc[startV][i]] != true) {
				checkBFS[vc[startV][i]] = true;
				queue.push(vc[startV][i]);
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &V);
	vc = new vector<int>[N + 1];
	int from, to;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &from, &to);
		vc[from].push_back(to);
		vc[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) {
		sort(vc[i].begin(), vc[i].end());
	}
	DFS(V);
	printf("\n");
	BFS(V);
	return 0;
}