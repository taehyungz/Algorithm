#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//트리의 지름 구하기
//1.임의의 점에서 가장 먼 거리의 점을 구함
//2.그 점에서 가장 먼 거리의 점과의 거리가 그 트리의 지름이다.
vector<int> vc[100001][2];
bool check[100001];
int max_ans, max_v;
void DFS(int V, const int max_dis) {
	check[V] = true;
	int v_size = vc[V][0].size();
	for (int i = 0; i < v_size; i++) {
		int nextv = vc[V][0][i];
		int nextdis = vc[V][1][i];
		if (check[nextv] == true) continue;
		check[nextv] = true;//다음 DFS전 방문했다고 표시
		DFS(nextv, max_dis + nextdis);
		check[nextv] = false;//방금 갔다온 길과는 별개의 사건이 진행되므로 안 간 것으로 표시
		
	}
	if (max_ans < max_dis) {
		max_ans = max_dis;
		max_v = V;
	}
}
int main() {
	int N;
	int V, nv, dis;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> V >> nv;
		while (nv != -1) {
			cin >> dis;
			vc[V][0].push_back(nv);
			vc[V][1].push_back(dis);
			cin >> nv;
		}
	}
	DFS(1, 0);//일단 1에서 가장 먼 점을 찾는다.
	fill(check, check + N+1, 0);
	max_ans = 0;
	DFS(max_v, 0);//찾은 점에서 가장 먼 점까지의 거리를 찾는다
	cout << max_ans;
	return 0;
}