#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> vc[1001];
bool check[1001];
int cnt;
void DFS(int N) {
	check[N] = true;
	for (int i = 0; i < vc[N].size(); i++) {
		int next_visit = vc[N][i];
		if (check[next_visit] == false) {
			DFS(next_visit);
		}
	}
}
int main() {
	int T, N;
	scanf("%d", &T);
	int arr[1001];
	while (T--) {
		cnt = 0;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
			check[i] = false;
			vc[i].clear();
		}
		for (int i = 1; i <= N; i++)
			vc[i].push_back(arr[i]);
		//인접리스트 입력 완료
		for (int i = 1; i <= N; i++) {
			if (check[i] == false) {
				DFS(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}