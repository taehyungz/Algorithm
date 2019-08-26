#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int num, bound;
	cin >> num >> bound;
	vector<int> vc;
	int count = 0;
	while (num != 0) {
		vc.push_back(num%bound);
		num /= bound;
		count++;
	}
	for (int i = count - 1; i >= 0; i--) {
		if (vc[i] < 10 && vc[i] >= 0) cout << vc[i];
		else
			printf("%c", 'A' + vc[i] - 10);
	}

	return 0;
}