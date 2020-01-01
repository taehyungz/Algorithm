#include <iostream>
using namespace std;

int main() {
	int W, M, K;//W는 여학생, M은 남학생, K는 인턴쉽 참여 인원
	int team = 0;
	cin >> W >> M >> K;
	while (K--) {
		//W=M*2이면 누구를 빼든지 같다
		if (W > 2 * M) {
			W--;
		}
		else {
			M--;
		}
	}
	while (M >= 1 && W >= 2) {
		M -= 1;
		W -= 2;
		team++;
	}
	cout << team;
	return 0;
}