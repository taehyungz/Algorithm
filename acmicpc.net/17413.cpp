#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector<string> vc;
	char ch;
	string str = "";
	while (1) {
		str = "";
		ch = getchar();
		if (ch == '<') {//<������ >���ö����� �Է�
			str += ch;
			while (1) {
				ch = getchar();
				if (ch != '>') str += ch;
				else break;
			}
			str += ch;
			vc.push_back(str);
		}
		else if (ch != '\n') {//���Ͱ� �ƴϸ�
			str += ch;
			while (1) {
				ch = getchar();
				if (ch != ' ' && ch != '\n' && ch != '<') str += ch;//�����̽�, ����, <�� �ƴ� ������ ��� �Է�
				else break;
			}
			vc.push_back(str);
			if (ch == ' ') vc.push_back(" ");//�����̽� ó��
			if (ch == '<') {
				str = "";
				str += ch;
				while (1) {
					ch = getchar();
					if (ch != '>') str += ch;
					else break;
				}
				str += ch;
				vc.push_back(str);
			}
		}
		if (ch == '\n') break;
	}
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[i].size(); j++) {
			if (vc[i][0] == '<') {
				cout << vc[i][j];
			}
			else {
				cout << vc[i][vc[i].size() - j - 1];
			}
		}
	}
	return 0;
}