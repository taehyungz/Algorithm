#include <iostream>
using namespace std;

int main() {
	//1 6 12 18 24
	//1  /  2~7  / 8~19  /  20~37
	int N;
	cin >> N;
	int count = 7;
	int rooms = 0;
	if (N == 1) rooms = 1;
	else if (N <= 7) rooms = 2;
	else {
		int plus = 12;
		while (count < N) {
			count += plus;
			plus += 6;
		}
		rooms = plus / 6;
	}
	cout << rooms;
	return 0;
}