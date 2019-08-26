#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int nums[10];
	int arr[42] = { 0 };
	for (int i = 0; i < 10; i++) {
		cin >> nums[i];
		nums[i] %= 42;
	}
	for (int i = 0; i < 10; i++) {
		arr[nums[i]] = 1;
	}
	int count = 0;
	for (int i = 0; i < 42; i++) {
		if (arr[i] == 1) count++;
	}
	cout << count;
	return 0;
}