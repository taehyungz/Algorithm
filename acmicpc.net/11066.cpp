#include <iostream>
#include <algorithm>
using namespace std;

int pages[501]; //k��° �������� ũ��
int cost[501][501]; //cost[y][x] -> Cy���� Cx������ �������� ���
int sum[501]; //k������ �� ������ ũ�� ��

int Min(int start, int round) {
	int minimum = 2000000000;//2*10�� 9��
	int temp;
	for (int i = start; i < start + round; i++) {
		temp = cost[start][i] + cost[i + 1][start + round] + sum[start + round] - sum[start - 1];
		minimum = min(minimum, temp);
	}
	return minimum;
}
int main() {
	int T, K;
	cin >> T;
	while (T--) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> pages[i];
			sum[i] = sum[i - 1] + pages[i];
		}
		for (int round = 1; round < K; round++) {
			//1����
			//1,2  2,3  3,4   ���ϰ�
			//1,3  2,4  3,5   ���ϰ�
			//1,4  2,5  3,6   ���ϴ� ������ ��
			for (int start = 1; start <= K - round; start++) {
				cost[start][start + round] = Min(start, round);
			}
		}
		cout << cost[1][K] << '\n';
	}
	return 0;
}