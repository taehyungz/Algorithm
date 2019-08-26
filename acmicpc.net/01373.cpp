#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	string str, ch8;
	stack<int> strst;
	int sum;
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i -= 3) {
		if (i == 0) ch8 = str[0];
		else if (i == 1) ch8 = str.substr(0, 2);
		else ch8 = str.substr(i - 2, 3);
		sum = 0;
		int cnt = 0;
		for (int j = ch8.size() - 1; j >= 0; j--) {
			sum += (ch8[j] - '0') * (int)pow(2, cnt++);
		}
		strst.push(sum);
	}
	while (!strst.empty()) {
		cout << strst.top();
		strst.pop();
	}
	return 0;
}