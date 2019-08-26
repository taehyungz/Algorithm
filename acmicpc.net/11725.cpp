#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
queue<int> q;//vc���� �� ������ ���� �̾��� �ִ� �������� ť�� ����
vector<int> vc[100001];//�Է¿� ���ؼ� �̾��� �� ������ ���
bool check[100001];//ť�� �����ϱ� ���� BFSŽ���� �� �� �湮���θ� ����
int parents[100001];//�� �����鿡 ���� �θ��带 ����
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