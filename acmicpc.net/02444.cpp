#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int line;
	cin >> line;

	for (int i = 1; i <= line; i++) {
		for (int j = line; j > i; j--) {
			cout << " ";
		}
		for (int k = 0; k < 2 * i - 1; k++) {
			cout << "*";
		}
		cout << endl;
	}

	for (int i = line - 1; i >= 0; i--) {
		for (int j = line; j > i; j--) {
			cout << " ";
		}
		for (int k = 0; k < 2 * i - 1; k++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}