#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<string, int>> namedic1;
	vector<string> namedic2;

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		namedic1.push_back(make_pair(name, i + 1));
		namedic2.push_back(name);
	}

	sort(namedic1.begin(), namedic1.end(), cmp);
	while (M--) {
		string question;
		cin >> question;
		if (question[0] >= '0' && question[0] <= '9') {
			int idx = stoi(question) - 1;
			cout << namedic2[idx] << '\n';
		}
		else {
			int left = 0;
			int right = N - 1;

			while (left <= right) {
				int mid = int((left + right) / 2);
				pair<string, int> pr = namedic1[mid];
				if (question > pr.first) {
					left = mid + 1;
				}
				else if (question < pr.first) {
					right = mid - 1;
				}
				else {
					cout << namedic1[mid].second << '\n';
					break;
				}
			}
		}
	}
}