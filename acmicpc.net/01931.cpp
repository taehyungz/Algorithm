#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> u, const pair<int, int> v) {
	if (u.second == v.second) {//11 12 22를 정렬할 때의 기준을 잡기 위해
		return u.first < v.first;
	}
	else {
		return u.second < v.second;
	}
}
int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> vc;
	for (int i = 0; i < N; i++) {
		int u, v;
		cin >> u >> v;
		vc.push_back(make_pair(u, v));
	}
	sort(vc.begin(), vc.end(), cmp);
	int start = 0;
	int end = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (end <= vc[i].first) {
			start = vc[i].first;
			end = vc[i].second;
			count++;
		}
	}
	cout << count;
	return 0;
}