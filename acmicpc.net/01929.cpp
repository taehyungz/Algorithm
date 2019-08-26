#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> M >> N;
	vector<int> vc(N + 1);
	vector<int> prime;
	for (int i = 2; i <= N; i++) {
		if (vc[i] == 0) {
			if (i >= M) cout << i << '\n';
			for (int j = i * 2; j <= N; j += i) {
				vc[j] = 1;
			}
		}
	}
}