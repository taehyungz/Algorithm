#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int heights[9];

int main() {
	int sum = 0;
	vector<int> vc;
	for (int i = 0; i < 9; i++) {
		cin >> heights[i];
		sum += heights[i];
	}
	for (int i = 0; i < 8; i++) {
		bool check = false;
		for (int j = i + 1; j < 9; j++) {
			if (sum - heights[i] - heights[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						vc.push_back(heights[k]);
						check = true;
					}
				}
			}
			if (check) break;
		}
		if (check) break;
	}
	sort(vc.begin(), vc.end());
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << '\n';
	}
}