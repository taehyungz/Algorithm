#include <iostream>
#include <stack>
using namespace std;
int arr[1001];
int dp[1001];
stack<int> st;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				if (max < dp[i]) max = dp[i];
			}
		}
	}
	if (max == 0) max = 1;
	for (int i = n; i > 0; i--) {
		if (max == 0) break;
		if (dp[i] == max) {
			st.push(arr[i]);
			max--;
		}
	}
	int stsize = st.size();
	cout << stsize << '\n';
	for (int i = 0; i < stsize; i++) {
		cout << st.top() << ' ';
		st.pop();
	}
	return 0;
}