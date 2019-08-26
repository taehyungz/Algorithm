#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int line;
	cin >> line;

	for (int i = 1; i <= line; i++) {
		if (i != line) {
			for (int j = line - i; j > 0; j--) cout << " ";
			for (int j = 0; j < 2 * i - 1; j++) {
				if (j == 0 || j == 2 * i - 2) cout << "*";
				else cout << " ";
			}

		}
		else {
			for (int j = 0; j < 2 * line - 1; j++) cout << "*";
		}
		cout << endl;
	}

	return 0;
}