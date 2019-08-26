#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int> &a) {
	long long sum = 0;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}