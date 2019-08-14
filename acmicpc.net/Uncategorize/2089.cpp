#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	string str = "";
	if (N == 0) {
		cout << 0;
		return 0;
	}
	while (N != 0) {
		if (N > 0 && N % 2 == 1) {
			str = '1' + str;
			N /= -2;
		}
		else if (N > 0) {
			str = '0' + str;
			N /= -2;
		}
		else if (N < 0 && (N*-1) % 2 == 1) {
			str = '1' + str;
			N = (N - 1) / -2;
		}
		else {
			str = '0' + str;
			N /= -2;
		}
	}
	cout << str;
	return 0;
}