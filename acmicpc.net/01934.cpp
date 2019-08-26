#include <iostream>
using namespace std;

int GCD(int numa, int numb) {
	if (numb == 0) return numa;
	else return GCD(numb, numa%numb);
}

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		long long x;
		int y;
		cin >> x >> y;
		cout << x * y / GCD(x, y) << '\n';
	}
	return 0;
}