#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//Ʈ���� ���� ���ϱ�
//1.������ ������ ���� �� �Ÿ��� ���� ����
//2.�� ������ ���� �� �Ÿ��� ������ �Ÿ��� �� Ʈ���� �����̴�.
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
		check[nextv] = true;//���� DFS�� �湮�ߴٰ� ǥ��
		DFS(nextv, max_dis + nextdis);
		check[nextv] = false;//��� ���ٿ� ����� ������ ����� ����ǹǷ� �� �� ������ ǥ��
		
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
	DFS(1, 0);//�ϴ� 1���� ���� �� ���� ã�´�.
	fill(check, check + N+1, 0);
	max_ans = 0;
	DFS(max_v, 0);//ã�� ������ ���� �� �������� �Ÿ��� ã�´�
	cout << max_ans;
	return 0;
}