#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int N, temp;
	scanf("%d", &N);
	vector<pair<int, int>> vc(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		vc[i] = make_pair(temp, i);
	}
	sort(vc.begin() + 1, vc.end());
	int diff;
	int max_diff = 0;
	for (int i = 1; i <= N; i++) {
		diff = vc[i].second - i;
		if (max_diff < diff) max_diff = diff;
	}
	printf("%d", max_diff + 1);
	return 0;
}