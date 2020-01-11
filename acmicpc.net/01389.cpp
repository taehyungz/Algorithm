#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int levels[101][101];
int kevin_number[101];
int main() {
	int N, M;
	cin >> N >> M;
	fill(&levels[0][0], &levels[100][101], 5000);
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		levels[a][b] = 1;
		levels[b][a] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int from = 1; from <= N; from++) {
			for (int to = 1; to <= N; to++) {
				if (levels[from][to] > levels[from][k] + levels[k][to]) {
					levels[from][to] = levels[from][k] + levels[k][to];
				}
			}
		}
	}
	int min = 5000;
	int person = 0;
	for (int from = 1; from <= N; from++) {
		for (int to = 1; to <= N; to++) {
			if (from == to) continue;
			kevin_number[from] += levels[from][to];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (min > kevin_number[i]) {
			min = kevin_number[i];
			person = i;
		}
	}
	cout << person;
	return 0;
}