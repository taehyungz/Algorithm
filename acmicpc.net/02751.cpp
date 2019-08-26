#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int N;
	int temp;
	scanf("%d", &N);
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &vec[i]);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		printf("%d\n", vec[i]);
	}
	return 0;
}