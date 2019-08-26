#include <iostream>
#include <vector>
using namespace std;

int GCD(int numa, int numb) {
	if (numb == 0) return numa;
	else return GCD(numb, numa%numb);
}

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<int> vc(N);
		long long sum = 0;
		for (int j = 0; j < N; j++)
			cin >> vc[j];
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < j; k++) {
				sum += GCD(vc[j], vc[k]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}