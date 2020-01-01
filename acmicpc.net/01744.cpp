#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//1보다 큰 양수는 큰 수끼리, -1보다 작은 음수는 작은 수끼리
//0은 묶지 않는 것이 좋지만 -1보다 작은 음수가 홀수개면 그중 
//가작 작은 수와 묶기, 1은 묶지 않기
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
		if (i + 1 < minus_nums.size() && minus_nums[i] < -1 && minus_nums[i + 1] < -1) {//두 수가 -1보다 작고, 뒷 수가 존재할 때
			sum += minus_nums[i] * minus_nums[i + 1];
			i += 2;
		}
		else if (minus_nums[i] == -1) { //수가 -1일때 (-1이 발견되면 그 이후의 수는 모두 -1이다)
			int minus_total = 0;
			if (minus_one % 2 == 0) minus_total = minus_one / 2;
			else if (zero_count == 0) minus_total = -1;
			sum += minus_total;
			break;
		}
		else { //한 수만 -1보다 작고, 그 뒤의 수는 -1이거나 없을 때
			if (i != minus_nums.size() - 1) {//만약 뒤에 -1이 있을 때
				sum += minus_nums[i++] * -1;
				minus_one--;
			}
			else if (zero_count > 0) {
				zero_count--;//0카운트가 있으면 이 수는 0으로 처리
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
		else { //한 수만 1보다 크고, 그 뒤의 수는 1이거나 없을 때
			sum += plus_nums[i++];
		}
	}
	cout << sum;
}