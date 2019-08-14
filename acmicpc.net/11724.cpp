#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> vc[1001];
bool check[1001];
int N, M, countconnected;
void DFS(int V) {
	check[V] = true;
	for (int i = 0; i < vc[V].size(); i++) {
		if (check[vc[V][i]] == false) {
			DFS(vc[V][i]);
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	int u, v;

	for (int i = 0; i < M; i++) {//그래프 인접리스트
		scanf("%d %d", &u, &v);
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {//연결성분 개수 조사
		if (check[i] == false) {
			countconnected++;
			DFS(i);
		}
	}
	printf("%d\n", countconnected);
	return 0;
}