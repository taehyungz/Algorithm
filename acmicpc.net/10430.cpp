#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	int num1 = (a + b) % c;
	int num2 = (a%c + b % c) % c;
	int num3 = (a*b) % c;
	int num4 = (a%c * b%c) % c;
	cout << num1 << '\n' << num2 << '\n' << num3 << '\n' << num4;
}