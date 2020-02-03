#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

bool op_cmp(char a, char b) {
	int pa, pb;
	if (a == '(') pa = 2; //��ȣ�� ��������� ���� ���� ��
	else if (a == '*' || a == '/') pa = 1; //�� ���Ĵ� ������ ������
	else pa = 0; //������ ������ ������
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
		if (s[i] >= 'A' && s[i] <= 'Z') { //�ǿ������̸� �ٷ� ����
			vc.push_back(s[i]);
		}
		else if (s[i] == '(') st.push(s[i]); //��ȣ�����̿��� �ٷ� ����
		else if (s[i] == ')') { //��ȣ �����̸�
			while (!st.empty() && st.top() != '(') { //������ ������� �ʰ� '('�� ���� ������ ���ÿ��� ����
				vc.push_back(st.top());
				st.pop();
			}
			st.pop();//(����
		}
		else { //�������̸�
			if (st.size() == 0) { //ó������ �׳� �־���
				st.push(s[i]);
				continue;
			}
			else if (st.top() != '(' && op_cmp(st.top(), s[i])) { //��ȣ ������ �ƴϰ� ������ ��������� �� ���� ��
				while (!st.empty() && st.top() != '(' && op_cmp(st.top(), s[i])) {
					vc.push_back(st.top());
					st.pop();
				}
				st.push(s[i]);

			}
			else {//���� ���� �����ڰ� ���ú��� �켱������ ���� ��
				st.push(s[i]);
			}
		}
	}
	while (!st.empty()) { //���ÿ� ���� �͵� ���
		vc.push_back(st.top());
		st.pop();
	}
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i];
	}
}