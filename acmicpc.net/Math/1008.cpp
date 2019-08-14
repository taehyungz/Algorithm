#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	printf("%.9lf", (double)a / b);
}