#include <iostream>
using namespace std;

int main() {
	int a, b, num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		cout << "Case #" << i + 1 << ":" << " " << a + b << endl;
	}
	return 0;
}