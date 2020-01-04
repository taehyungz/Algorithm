#include <iostream>
using namespace std;
bool open[101];
int main() {
	int T;
	int n;
	int count = 0;
	cin >> T;
	while (T--) {
		cin >> n; // 방 개수
		for (int round = 1; round <= n; round++) { //n라운드만큼 진행
			for (int room = 1; room <= n; room++) {
				if (room%round == 0) {
					open[room] = !open[room];
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (open[i]) count++;
		}
		cout << count << '\n';
		for (int i = 0; i <= n; i++) {
			open[i] = false;
		}
		count = 0;
	}
	return 0;
}