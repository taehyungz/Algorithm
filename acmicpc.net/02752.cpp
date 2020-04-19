#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &vc, int start, int end) {
	if (start >= end) return;
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	while (i <= j) {
		while (i <= end && vc[i] <= vc[pivot]) {
			i++;
		}
		while (j > start && vc[j] >= vc[pivot]) j--;
		if (i <= j) swap(vc[i], vc[j]);
		else swap(vc[pivot], vc[j]);
	}
	QuickSort(vc, start, j - 1);
	QuickSort(vc, j + 1, end);
}
int main() {
	int N;
	N = 3;
	vector<int> vc;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vc.push_back(num);
	}
	QuickSort(vc, 0, N - 1);
	for (auto i : vc) cout << i << ' ';
}