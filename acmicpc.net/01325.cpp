#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> trust[10001];//신뢰 배열
bool visit[10001];//방문 여부
int nums[10001]; //해킹 개수
vector<int> biggest[10001];

void DFS(int from) {
	visit[from] = true;
	for (int i = 0; i < trust[from].size(); i++) {
		if (!visit[trust[from][i]]) DFS(trust[from][i]);//이미 방문했던 컴퓨터는 방문 X
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		trust[B].push_back(A);//방향 에지 추가
	}
	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		DFS(i);//깊이우선 탐색
		for (int j = 1; j <= N; j++) {
			if (visit[j]) nums[i]++;//방문한 개수 계산
		}
	}
	int big_num = 0;
	for (int i = 1; i <= N; i++) {
		biggest[nums[i]].push_back(i);
		big_num = big_num > nums[i] ? big_num : nums[i];
	}
	for (int i = 0; i < biggest[big_num].size(); i++) {
		cout << biggest[big_num][i] << ' ';
	}
	return 0;
}