#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int div = N / 5;
	int num = 0;
	int min = 9999;
	for (int i = div; i >= 0; i--) {
		int CN = N - 5 * i;
		if (CN % 3 == 0) {
			num = num + i + CN / 3;
			if (min > num) min = num;
		}
	}
	if (min == 9999) cout << -1;
	else cout << min;
	return 0;
}