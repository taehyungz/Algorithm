#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int line;
	cin >> line;

	for (int i = line; i > 0; i--) {
		for (int j = line; j > i; j--) cout << " ";
		for (int j = 0; j < 2 * i - 1; j++) cout << "*";
		cout << endl;
	}
	for (int i = 2; i <= line; i++) {
		for (int j = line; j > i; j--) cout << " ";
		for (int j = 0; j < 2 * i - 1; j++) cout << "*";
		cout << endl;
	}

	return 0;
}