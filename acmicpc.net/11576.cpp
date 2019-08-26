#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	int A, B;
	int m;//A���� ���� �ڸ���
	int sum = 0;//A������ 10�������� �ٲ� �� ���
	stack<int> stk;
	string converted_str = "";
	vector<int> vec;
	cin >> A >> B;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	for (int i = m - 1; i >= 0; i--) {
		sum = sum + pow(A, m - i - 1)*vec[i];
	}
	while (sum != 0) {
		stk.push(sum % B);
		sum /= B;
	}
	cout << stk.top();
	stk.pop();
	while (!stk.empty()) {
		cout << ' ' << stk.top();
		stk.pop();
	}
	return 0;
}