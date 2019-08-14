#include <iostream>
#include <string>
#include <stack>
using namespace std;

int count_nums(string s) {
	stack<int> st;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (st.top() == i - 1) {
			st.pop();
			sum += st.size();
		}
		else {
			st.pop();
			sum++;
		}

	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	cout << count_nums(s) << '\n';
	return 0;
}