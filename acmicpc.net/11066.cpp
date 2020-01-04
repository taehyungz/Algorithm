#include <iostream>
#include <algorithm>
using namespace std;

int pages[501]; //k번째 페이지의 크기
int cost[501][501]; //cost[y][x] -> Cy부터 Cx까지의 최종파일 비용
int sum[501]; //k까지의 각 파일의 크기 합

int Min(int start, int round) {
	int minimum = 2000000000;//2*10의 9승
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
			//1라운드
			//1,2  2,3  3,4   구하고
			//1,3  2,4  3,5   구하고
			//1,4  2,5  3,6   구하는 식으로 함
			for (int start = 1; start <= K - round; start++) {
				cost[start][start + round] = Min(start, round);
			}
		}
		cout << cost[1][K] << '\n';
	}
	return 0;
}