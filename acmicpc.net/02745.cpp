#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string str;
	int B;
	cin >> str >> B;
	int cnt = 0;
	int sum = 0;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] >= '0' && str[i] <= '9') sum += (str[i] - '0') * (int)pow(B, cnt++);
		else sum += (str[i] - 'A' + 10)*(int)pow(B, cnt++);
	}
	cout << sum;
	return 0;
}