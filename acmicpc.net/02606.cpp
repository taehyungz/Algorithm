#include <iostream>
#include <vector>
using namespace std;
vector<int> vc[101];
bool visited[101];
void DFS(int from) {
	visited[from] = true;
	for (int i = 0; i < vc[from].size(); i++) {
		if (!visited[vc[from][i]]) DFS(vc[from][i]);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	DFS(1);
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) count++;
	}
	cout << --count;
	return 0;
}