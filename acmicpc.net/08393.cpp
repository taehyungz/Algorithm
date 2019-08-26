#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int num;
	int sum = 0;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		sum += i;
	}
	cout << sum;
	return 0;
}