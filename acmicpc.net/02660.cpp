#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int group[51][51];//그룹 정보
int max_score[51];//각 사람들의 점수
vector<int> vc;//회장 후보
int minimum = 50;//회장후보의 점수
int main() {
	int n;
	int a, b;
	cin >> n;
	fill(&group[0][0], (&group[50][50]) + 1, 50);
	for (int i = 1; i <= n; i++) {
		group[i][i] = 0;
	}
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		group[a][b] = 1;
		group[b][a] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				if (group[i][j] > group[i][k] + group[k][j]) {
					group[i][j] = group[i][k] + group[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int each_max = 0;
		for (int j = 1; j <= n; j++) {
			each_max = each_max > group[i][j] ? each_max : group[i][j];
		}
		max_score[i] = each_max;
		if (minimum > max_score[i]) {
			minimum = max_score[i];
			vc.clear();
			vc.push_back(i);
		}
		else if (minimum == max_score[i]) {
			vc.push_back(i);
		}
	}
	cout << minimum << ' ' << vc.size() << '\n';
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << ' ';
	}
}