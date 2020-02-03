#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b) {
	if (b == 0) return a;
	else return GCD(b, a%b);
}
int main() {
	int N, S;
	cin >> N >> S;
	vector<int> vc(N);
	int max = 0;
	vector<int> gcd_nums;
	for (int i = 0; i < N; i++) {
		cin >> vc[i];
		int a = S - vc[i];
		int b = vc[i] - S;
		int num = a > b ? a : b;
		gcd_nums.push_back(num);//gcd_nums에 들어있는 수들의 최대공약수를 구한다
	}
	int temp_gcd = gcd_nums[0];
	for (int i = 1; i < gcd_nums.size(); i++) {
		int a = temp_gcd;
		int b = gcd_nums[i];
		temp_gcd = GCD(a, b);
	}
	cout << temp_gcd;
}