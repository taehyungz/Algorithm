#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int num;
	cin >> num;
	for (int i = num; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) cout << " ";
		for (int k = i - 1; k < num; k++) cout << "*";
		cout << endl;
	}
	return 0;
}