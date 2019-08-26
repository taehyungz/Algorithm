#include <iostream>
using namespace std;

int isPrime(const int M) {
	if (M < 2) return 0;
	for (int i = 2; i*i <= M; i++) {
		if (M%i == 0) return 0;
	}
	return 1;
}
int main() {
	int N;
	int count = 0;
	cin >> N;
	int M;
	for (int i = 0; i < N; i++) {
		cin >> M;
		if (isPrime(M)) {
			count++;
		}
	}
	cout << count;
}