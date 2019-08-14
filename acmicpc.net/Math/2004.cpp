#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//n * n-1 * ~~ n-m+1  / m!
	// n!/m! (n-m)!
	int n, m;
	cin >> n >> m;
	long long count2 = 0;
	long long count5 = 0;
	for (long long i = 2; i <= n; i *= 2) {
		count2 += n / i;
	}
	for (long long i = 2; i <= m; i *= 2) {
		count2 -= m / i;
	}
	for (long long i = 2; i <= n - m; i *= 2) {
		count2 -= (n - m) / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		count5 += n / i;
	}
	for (long long i = 5; i <= m; i *= 5) {
		count5 -= m / i;
	}
	for (long long i = 5; i <= n - m; i *= 5) {
		count5 -= (n - m) / i;
	}
	cout << min(count2, count5);
	return 0;
}