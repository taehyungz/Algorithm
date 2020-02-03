#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int number[1000001];
int number_cnt[1000001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) { //1부터 N까지 저장
		cin >> number[i];
		number_cnt[number[i]]++;
	}
	stack<int> st;
	vector<int> ans(N + 1);
	number[0] = 0;
	number_cnt[0] = 1000001;
	st.push(0);
	for (int i = N; i > 0; i--) {
		if (number_cnt[number[i]] < number_cnt[st.top()]) {
			ans[i] = st.top();
			st.push(number[i]);//스택에는 수를 넣음
		}
		else {
			while (number_cnt[number[i]] >= number_cnt[st.top()]) {
				st.pop();
			}
			if (st.size() == 1) ans[i] = -1;
			else ans[i] = st.top();
			st.push(number[i]);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << (ans[i] == 0 ? -1 : ans[i]) << ' ';
	}
}