#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int line;
	cin >> line;

	for (int i = 0; i < line; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		for (int k = 0; k < line - i - 1; k++) {
			cout << "  ";
		}
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = line - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		for (int k = 0; k < line - i - 1; k++) {
			cout << "  ";
		}
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}