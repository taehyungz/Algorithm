#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[100000];
//3�� ��� ���� + ���� 0�� ������ �ȴ�
//3�� ��� ������ : �� �ڸ����� ���� 3�� ���
bool cmp(const int& a, const int&b) {
	return a > b;
}
int main() {
	string s;
	int sum = 0;
	int zero_cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		arr[i] = s[i] - '0';
		sum += arr[i];
		if (arr[i] == 0) zero_cnt++;
	}
	if (zero_cnt == 0 || sum % 3 == 0 ) {
		cout << -1;
		return 0;
	}
	sort(arr, arr + s.size(), cmp);
	for (int i = 0; i < s.size(); i++) cout << arr[i];
	return 0;
}