#include <iostream>
#include <vector>
using namespace std;

bool prime[1000001];
vector<int> primevc;//소수들 저장
int Gold(int N) {
	int count = 0;
	for (int i = 0; i < primevc.size() && primevc[i] <= (1 + N) / 2; i++) {
		if (prime[N - primevc[i]])
			count++;
	}
	return count;
}
void GetPrime() {
	int max = 1000000;
	for (int i = 2; i <= max; i++) prime[i] = true;
	for (int i = 2; i*i <= max; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= max; j += i) prime[j] = false;
		}
	}
	for (int i = 2; i <= max; i++) if (prime[i]) primevc.push_back(i);
}
int main() {
	int T;
	cin >> T;
	GetPrime();
	while (T--) {
		int N;
		cin >> N;
		cout << Gold(N) << '\n';
	}
}