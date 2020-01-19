#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vc;
int main() {
	int N;
	char ch;
	bool zero = false;
	int sum = 0;
	while (ch = getchar()) {
		if (ch == '\n') break;
		else vc.push_back(ch - '0');
		if (ch == '0') zero = true;
		sum += (ch - '0');
	}
	//30의 배수-> 뒤에 무조건 0이 필요 + 3의 배수
	if (!zero || sum % 3 != 0) {
		cout << -1;
		return 0;
	}
	sort(vc.begin(), vc.end());
	for (int i = vc.size() - 1; i >= 0; i--) {
		cout << vc[i];
	}
	return 0;
}