#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int arr[100000];
vector<char> op;
stack<int> st;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	for (int i = 1; cnt < n; cnt++) {
		while (i < arr[cnt]) {
			st.push(i++);
			op.push_back('+');
		}
		if (i == arr[cnt]) {
			op.push_back('+');
			op.push_back('-');
			i++;
			continue;
		}
		else {
			if (st.top() == arr[cnt]) {
				op.push_back('-');
				st.pop();
				continue;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	for (int i = 0; i < op.size(); i++) {
		cout << op[i] << '\n';
	}
}