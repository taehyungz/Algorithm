#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int arr[9];
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	int max = arr[0];
	int idx = 0;
	for (int i = 1; i < 9; i++) {
		if (max < arr[i]) {
			idx = i;
			max = arr[i];
		}
	}
	cout << max << '\n' << idx + 1;
	return 0;
}