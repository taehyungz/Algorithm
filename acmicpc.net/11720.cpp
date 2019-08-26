#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	int num, sum, a;
	sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%1d", &a);
		sum += a;
	}
	cout << sum;
	return 0;
}