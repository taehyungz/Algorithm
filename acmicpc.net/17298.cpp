#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> number(N);
	vector<int> ans(N);
	stack<int> st;
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	st.push(1000001);//ÃÖ´ë¼ö
	for (int i = N - 1; i >= 0; i--) {
		if (number[i] < st.top()) {
			if (i == N - 1) ans[i] = -1;
			else ans[i] = st.top();
			st.push(number[i]);
		}
		else {
			while (number[i] >= st.top()) {
				st.pop();
			}
			ans[i] = st.top();
			st.push(number[i]);
		}
	}
	for (int i = 0; i < N; i++) {
		cout << (ans[i] == 1000001 ? -1 : ans[i]) << ' ';
	}
}