#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string temp = "";
	vector<int> numbers;
	vector<char> pm;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
		}
		else {
			numbers.push_back(stoi(temp));
			temp = "";
			pm.push_back(s[i]);
		}
	}
	numbers.push_back(stoi(temp));//����, ��ȣ ���� �Ϸ�
	int tempnum = 0;//-�� ������ �� ���� -�� ������ �������� ���� ���� �����ϴ� ����
	int pmcnt = 0;//��ȣ���� ������ ���Ϳ����� �ε���
	int sum = numbers[0];//�ʱ갪
	for (int i = 1; i < numbers.size(); i++) {
		if (pm[pmcnt] == '-') {//-�̸�
			do {//do while �� ������ -���İ� ���� ���� �ֱ� ������
				tempnum += numbers[i++];
				pmcnt++;
			} while (pmcnt < pm.size() && pm[pmcnt] == '+');//pmcnt�� pm�� ũ�⸦ ���� �ʰ� pm[pmcnt]�� ���ϱ� �̸� �ݺ�
			i--;//for������ i�� �÷��ֹǷ� �ϳ� ����
			sum -= tempnum;
		}
		else {
			pmcnt++;
			tempnum = numbers[i];
			sum += tempnum;
		}
		tempnum = 0;//tempnum �ʱ�ȭ
	}
	cout << sum;
	return 0;
}