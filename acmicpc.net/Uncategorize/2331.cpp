#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> vc;
int idx;
bool check_number(int N) {//있으면 true 반환
	for (int i = 0; i < vc.size(); i++) {
		if (vc[i] == N) {
			idx = i;
			return true;
		}
	}
	return false;
}
int getNum(int num, const int P) {
	int ans = 0;
	int temp;
	while (num > 0) {
		temp = num % 10;
		ans += (int)pow(temp, P);
		num /= 10;
	}
	return ans;
}
int main() {
	int A, P;
	cin >> A >> P;
	vc.push_back(A);
	while (1) {
		int num = getNum(vc.back(), P);
		if (check_number(num)) {
			cout << idx << '\n';
			return 0;
		}
		else vc.push_back(num);
	}
}