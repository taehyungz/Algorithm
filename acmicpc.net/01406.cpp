#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	stack<char> left, right;
	string orders;
	int num;
	cin >> orders;
	cin >> num;
	for (int i = 0; i < orders.size(); i++) {
		left.push(orders[i]);
	}
	while (num--) {
		char what;
		cin >> what;
		switch (what) {
		case 'L':
			if (left.size() == 0) continue;
			right.push(left.top());
			left.pop();
			break;
		case 'D':
			if (right.size() == 0) continue;
			left.push(right.top());
			right.pop();
			break;
		case 'B':
			if (left.size() == 0) continue;
			left.pop();
			break;
		case 'P':
			char data;
			cin >> data;
			left.push(data);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	return 0;
}