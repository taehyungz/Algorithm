#include <iostream>
using namespace std;

int main() {
	int num;
	char chs[4];
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> chs;
		cout << chs[0] + chs[2] - '0' - '0' << endl;
	}
	return 0;
}