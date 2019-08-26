#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int A;
	cin >> A;
	int B = -1;
	int CA = A;
	int count = 0;
	while (CA != B) {
		if (A < 10) {
			B = 11 * A;
			count++;
		}
		else {
			int C = A / 10 + A % 10;
			C = C % 10;
			int D = A % 10;
			B = D * 10 + C;
			count++;
		}
		if (A != B) {
			A = B;
		}
	}
	cout << count;
	return 0;
}