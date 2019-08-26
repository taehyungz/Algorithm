#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int line;
	cin >> line;

	for (int i = 0; i < line; i++) {
		for (int j = line - i - 1; j > 0; j--) cout << " ";
		for (int j = 0; j <= i; j++) {
			if (j != i) cout << "* ";
			else cout << "*";
		}
		cout << endl;
	}

	return 0;
}