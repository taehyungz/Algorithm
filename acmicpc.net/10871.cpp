#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int N, X;
	int count = 0;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a < X) {
			count++;
		}
		if (a < X && count == 1) cout << a;
		else if (a < X) cout << " " << a;
	}

}