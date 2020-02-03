#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

bool op_cmp(char a, char b) {
	int pa, pb;
	if (a == '(') pa = 2; //괄호의 연산순위를 가장 높게 함
	else if (a == '*' || a == '/') pa = 1; //그 이후는 곱셈과 나눗셈
	else pa = 0; //덧셈과 뺄셈은 최하위
	if (b == '(') pb = 2;
	else if (b == '*' || b == '/') pb = 1;
	else pb = 0;
	return pa >= pb;
}
int main() {
	string s;
	stack<char> st;
	cin >> s;
	vector<char> vc;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') { //피연산자이면 바로 넣음
			vc.push_back(s[i]);
		}
		else if (s[i] == '(') st.push(s[i]); //괄호시작이여도 바로 넣음
		else if (s[i] == ')') { //괄호 닫힘이면
			while (!st.empty() && st.top() != '(') { //스택이 비어있지 않고 '('가 나올 때까지 스택에서 빼줌
				vc.push_back(st.top());
				st.pop();
			}
			st.pop();//(제거
		}
		else { //연산자이면
			if (st.size() == 0) { //처음에는 그냥 넣어줌
				st.push(s[i]);
				continue;
			}
			else if (st.top() != '(' && op_cmp(st.top(), s[i])) { //괄호 시작이 아니고 스택의 연산순위가 더 높을 때
				while (!st.empty() && st.top() != '(' && op_cmp(st.top(), s[i])) {
					vc.push_back(st.top());
					st.pop();
				}
				st.push(s[i]);

			}
			else {//현재 보는 연산자가 스택보다 우선순위가 높을 때
				st.push(s[i]);
			}
		}
	}
	while (!st.empty()) { //스택에 남은 것들 출력
		vc.push_back(st.top());
		st.pop();
	}
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i];
	}
}