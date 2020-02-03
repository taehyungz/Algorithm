#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int main() {
	int N;//피연산자 개수
	cin >> N;
	string s;//후위 표기식
	cin >> s;
	stack<double> st;
	vector<int> vc(N);
	for (int i = 0; i < N; i++) {
		cin >> vc[i];
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < 'A' || s[i] > 'Z') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			switch (s[i]) {
			case '+':
				st.push(b + a);
				break;
			case '-':
				st.push(b - a);
				break;
			case '*':
				st.push(b*a);
				break;
			case '/':
				st.push(b / a);
				break;
			}
		}
		else {
			st.push(vc[s[i] - 'A']);
		}
	}
	printf("%0.2f", st.top());
}