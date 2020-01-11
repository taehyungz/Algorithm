#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int numbers[12];
vector<int> vc;
void DFS(int k, int idx, int level) {
	if (level != 6) {
		for (int i = idx; i + (5 - level) < k; i++) {
			vc.push_back(numbers[i]);
			DFS(k, i + 1, level + 1);
			vc.pop_back();
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			cout << vc[i] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	int k;
	while (1) {
		cin >> k;
		if (k == 0) return 0;
		memset(numbers, 0, sizeof(numbers));
		for (int i = 0; i < k; i++) {
			cin >> numbers[i];
		}
		DFS(k, 0, 0);
		cout << '\n';
	}
}