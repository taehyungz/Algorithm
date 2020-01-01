#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//1���� ū ����� ū ������, -1���� ���� ������ ���� ������
//0�� ���� �ʴ� ���� ������ -1���� ���� ������ Ȧ������ ���� 
//���� ���� ���� ����, 1�� ���� �ʱ�
bool cmp(const int& a, const int& b) {
	return a > b;
}
int main() {
	int N, temp;
	int zero_count = 0;
	int minus_one = 0;
	int plus_one = 0;
	vector<int> plus_nums;
	vector<int> minus_nums;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) {
			zero_count++;
		}
		else if (temp < 0) {
			minus_nums.push_back(temp);
			if (temp == -1) minus_one++;
		}
		else {
			plus_nums.push_back(temp);
			if (temp == 1) plus_one++;
		}
	}
	int sum = 0;
	sort(minus_nums.begin(), minus_nums.end());
	for (int i = 0; i < minus_nums.size();) {
		if (i + 1 < minus_nums.size() && minus_nums[i] < -1 && minus_nums[i + 1] < -1) {//�� ���� -1���� �۰�, �� ���� ������ ��
			sum += minus_nums[i] * minus_nums[i + 1];
			i += 2;
		}
		else if (minus_nums[i] == -1) { //���� -1�϶� (-1�� �߰ߵǸ� �� ������ ���� ��� -1�̴�)
			int minus_total = 0;
			if (minus_one % 2 == 0) minus_total = minus_one / 2;
			else if (zero_count == 0) minus_total = -1;
			sum += minus_total;
			break;
		}
		else { //�� ���� -1���� �۰�, �� ���� ���� -1�̰ų� ���� ��
			if (i != minus_nums.size() - 1) {//���� �ڿ� -1�� ���� ��
				sum += minus_nums[i++] * -1;
				minus_one--;
			}
			else if (zero_count > 0) {
				zero_count--;//0ī��Ʈ�� ������ �� ���� 0���� ó��
				i++;
			}
			else sum += minus_nums[i++];
		}
	}
	sort(plus_nums.begin(), plus_nums.end(), cmp);
	for (int i = 0; i < plus_nums.size();) {
		if (i + 1 < plus_nums.size() && plus_nums[i] > 1 && plus_nums[i + 1] > 1) {
			sum += plus_nums[i] * plus_nums[i + 1];
			i += 2;
		}
		else if (plus_nums[i] == 1) {
			sum += plus_one;
			break;
		}
		else { //�� ���� 1���� ũ��, �� ���� ���� 1�̰ų� ���� ��
			sum += plus_nums[i++];
		}
	}
	cout << sum;
}