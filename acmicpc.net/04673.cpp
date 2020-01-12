//4673¹ø
#include <iostream>
using namespace std;
bool check[10001];

void Count(int i) {
	int sum = i;
	while (i > 0) {
		sum += i % 10;
		i /= 10;
	}
	if (sum <= 10000) {
		Count(sum);
		check[sum] = true;
	}
}
int main() {
	for (int i = 1; i <= 10000; i++) {
		Count(i);
	}
	for (int i = 1; i <= 10000; i++) {
		if (!check[i]) cout << i << '\n';
	}
}