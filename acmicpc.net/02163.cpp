#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	cout << (N - 1) * M + (M - 1); // 한 줄을 모두 자르는데 N-1번, 그것이 M개, M줄을 자르는데 M-1번
	return 0;
}