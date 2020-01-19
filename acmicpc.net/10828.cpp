#include <iostream>
#include <cstring>
#include <stack>

using namespace std;
int main() {
	int N;
	stack<int> stk;
	cin >> N;
	while (N--) {
		char str[10];
		cin >> str;
		if (strcmp(str, "push") == 0) {
			int a;
			cin >> a;
			stk.push(a);
		}
		else if (strcmp(str, "top") == 0) {
			if (stk.size() > 0) cout << stk.top() << '\n';
			else cout << -1 << '\n';
		}
		else if (strcmp(str, "size") == 0) {
			cout << stk.size() << '\n';
		}
		else if (strcmp(str, "pop") == 0) {
			if (stk.size() > 0) {
				cout << stk.top() << '\n';
				stk.pop();
			}
			else cout << -1 << '\n';
		}
		else if (strcmp(str, "empty") == 0) {
			cout << stk.empty() << '\n';
		}
	}
}