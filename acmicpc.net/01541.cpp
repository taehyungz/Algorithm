#include <iostream>
#include <vector>
using namespace std;
vector<char> op;
vector<int> numbers;
int main() {
	int sum = 0;
	while (1) {
		char ch = getchar();
		if (ch == '\n') {
			numbers.push_back(sum);
			break;
		}
		else if (ch >= '0' && ch <= '9') {
			sum *= 10;
			sum = sum + ch - '0';
		}
		else {
			numbers.push_back(sum);
			sum = 0;
			op.push_back(ch);
		}
	}//����, ��ȣ ���� �Ϸ�
	sum = numbers[0];
	int subsum = 0;
	for (int i = 1, j = 0; i < numbers.size(); i++) {
		if (op[j] == '-') {//��ȣ�� -�̸�
			subsum = numbers[i++];
			j++;
			while (j < op.size() && op[j++] != '-') {//���� ���̳ʽ��� ���ö����� subsum�� ����
				subsum += numbers[i++];
			}
			i--;
			j--;//�� while������ i�� j�� 1�� �������� �Ϸ�����Ƿ� ����
			sum -= subsum;//-�� ������̿����Ƿ� ����
			subsum = 0;//subsum �ʱ�ȭ
		}
		else {
			sum += numbers[i];
			j++;
		}
	}
	cout << sum;
	return 0;
}