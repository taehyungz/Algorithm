#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector <double> score(N);
	for (int i = 0; i < N; i++) cin >> score[i];
	sort(score.begin(), score.end());
	int max = score[N - 1];
	double sum = 0;
	for (int i = 0; i < N; i++) {
		score[i] = score[i] / max * 100;
		sum += score[i];
	}
	sum = sum / N;
	printf("%0.2lf", sum);
}