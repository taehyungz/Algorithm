#include <iostream>
#include <utility>
using namespace std;
int main() {
	int N, M;//N은 세로, M은 가로
	cin >> N >> M;
	//2칸 위, 1칸 오른쪽 -> N:-2, M:+1
	//1칸 위, 2칸 오른쪽 -> N:-1, M:+2
	//1칸 아래, 2칸 오른쪽 -> N:+1, M:+2
	//2칸 아래, 1칸 오른쪽 -> N:+2, M:+1
	pair<int, int> n_pos = make_pair(N - 1, 0);//y,x
	bool check = false;//3번만에 갈 수 있는지 체크.
	bool checks[4] = { false, false, false, false };
	int count = 5;//4번 이상 움직일 경우

	int ymod = 2;
	int xmod = 1;
	int y_cond = -1;//위방향으로 가는중 

	if (M < 5 && N>2) {
		cout << M;
		return 0;
	}
	else if (M < 7 && N>2) {
		cout << 4;
		return 0;
	}
	if (N == 1) {
		cout << 1;
		return 0;
	}
	else if (N == 2) {
		if (M <= 8) cout << (1 + M) / 2;
		else cout << 4;
		return 0;
	}
	//가로가 4칸 이상이여서 모든 방법을 1번 이상 써야할 때
	n_pos.second = 6;
	while (n_pos.second < M - 1) {
		if (n_pos.first == 0) {
			y_cond *= -1;
		}
		else if (n_pos.first == N - 1 && n_pos.second != 0) {
			y_cond *= -1;
		}
		n_pos.first += y_cond * ymod;
		n_pos.second += 1;
		count++;
	}
	cout << count;
	return 0;
}