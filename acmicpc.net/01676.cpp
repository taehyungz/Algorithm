#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	if (N == 0) {
		cout << 0;
		return 0;
	}
	int count2 = 0;
	int count5 = 0;

	for (int i = 1; i <= N; i++) {
		if (i % 2 == 0) {
			int j = i;
			while (j % 2 == 0 && j > 0) {
				count2++;
				j /= 2;
			}
		}
		if (i % 5 == 0) {
			int j = i;
			while (j % 5 == 0 && j > 0) {
				count5++;
				j /= 5;
			}
		}
	}
	cout << min(count2, count5);
}