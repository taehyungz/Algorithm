#include <iostream>
using namespace std;

int fac(int N) {
	int gob = 1;
	for (int i = 2; i <= N; i++) {
		gob = gob * i;
	}
	return gob;
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << fac(N);
	return 0;
}