#include <iostream>
using namespace std;

int main() {
	//1 6 12 18 24
	//1  /  2~7  / 8~19  /  20~37
	int N;
	cin >> N;
	int count = 0;
	int plus = 1;
	while (count < N) {
		count += plus;
		plus++;
	}//plus-1��° �밢�ٿ� n��° ���� �ִ�. / �и�+���� = plus+1
	//�� �밢���� ù ��° ���� 1/plus
	int scount = count - plus + 1;
	int diff = N - scount;
	if ((plus - 1) % 2 == 0) {
		cout << diff << '/' << plus - diff;
	}
	else {
		cout << plus - diff << '/' << diff;
	}
}