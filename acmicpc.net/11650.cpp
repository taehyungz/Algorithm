#include <iostream>
#include<algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
	vector<pair<int, int>> vc;
	int N, x, y;
	cin >> N;
	pair<int, int> pr;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		pr = make_pair(x, y);
		vc.push_back(pr);
	}
	sort(vc.begin(), vc.end());
	for (int i = 0; i < N; i++) {
		cout << vc[i].first << ' ' << vc[i].second << '\n';
	}
	return 0;
}