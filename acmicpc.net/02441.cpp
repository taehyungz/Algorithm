#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int num;
	cin >> num;
	for (int i = num; i > 0; i--) {
		for (int k = num; k > i; k--) cout << " ";
		for (int j = 0; j < i; j++) cout << "*";
		cout << endl;
	}
	return 0;
}