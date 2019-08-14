#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

bool ans;
vector<int> vc[20001];
int check[20001];
void BFS(int V) {
	queue<int> q;
	check[V] = 1;
	q.push(V);
	while (!q.empty()) {
		int nowV = q.front();
		q.pop();
		for (int i = 0; i < vc[nowV].size(); i++) {
			int nextV = vc[nowV][i];
			if (check[nextV] == 0 && check[nowV] == 1) {//미방문 && 지금이 1번
				q.push(nextV);
				check[nextV] = 2;//다음 방문노드는 2번
			}
			else if (check[nextV] == 0 && check[nowV] == 2) {//미방문 && 지금이 2번
				q.push(nextV);
				check[nextV] = 1;
			}
			else if (check[nextV] == check[nowV]) {
				ans = false;
				return;
			}
		}
	}
	ans = true;
	return;
}
int main() {
	int K, V, E;
	int u, v;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &V, &E);
		for (int j = 0; j <= V; j++) {//초기화(여러번 사용하기 때문에)
			vc[j].clear();
			check[j] = 0;
		}
		for (int j = 0; j < E; j++) {//간선 정보 입력
			scanf("%d %d", &u, &v);
			vc[u].push_back(v);
			vc[v].push_back(u);
		}
		for (int j = 1; j <= V; j++) {
			if (check[j] == 0) {
				BFS(j);
			}
			if (ans == false) {//한 번이라도 false가 나오면 NO를 출력
				printf("NO\n");
				break;
			}
		}
		if (ans == true) printf("YES\n");
	}
	return 0;
}