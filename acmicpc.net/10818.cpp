#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int num, x, min, max;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> x;
		if (i == 0) {
			min = x;
			max = x;
		}
		if (x < min) min = x;
		if (x > max) max = x;
	}
	cout << min << " " << max;
	return 0;
}