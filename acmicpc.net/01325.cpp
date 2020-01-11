#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> trust[10001];//�ŷ� �迭
bool visit[10001];//�湮 ����
int nums[10001]; //��ŷ ����
vector<int> biggest[10001];

void DFS(int from) {
	visit[from] = true;
	for (int i = 0; i < trust[from].size(); i++) {
		if (!visit[trust[from][i]]) DFS(trust[from][i]);//�̹� �湮�ߴ� ��ǻ�ʹ� �湮 X
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		trust[B].push_back(A);//���� ���� �߰�
	}
	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		DFS(i);//���̿켱 Ž��
		for (int j = 1; j <= N; j++) {
			if (visit[j]) nums[i]++;//�湮�� ���� ���
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