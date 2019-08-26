#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		int N;
		cin >> N;
		int *score = new int[N];
		int sum = 0;
		for (int j = 0; j < N; j++) {
			cin >> score[j];
			sum += score[j];
		}
		double avg = sum / N;
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (avg < score[j]) count++;
		}
		double pec = (double)count / N * 100000 + 0.5;
		pec = floor(pec);
		pec = pec / 1000;
		printf("%0.3lf%%\n", pec);
	}
}