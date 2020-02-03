#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> costs(N + 1);
	vector<int> dp_cost(N + 1); //i�� �� ���� �ּڰ�
	fill(dp_cost.begin() + 1, dp_cost.end(), 10000000);
	for (int i = 1; i <= N; i++) {
		cin >> costs[i]; //i�� ����ִ� ī������ ����
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= costs.size() && i >= j; j++) {
			if (dp_cost[i] > dp_cost[i - j] + costs[j]) dp_cost[i] = dp_cost[i - j] + costs[j];
		}
	}
	cout << dp_cost[N];
	return 0;
}