#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int music[8];
	int check = 0;
	for (int i = 0; i < 8; i++) {
		cin >> music[i];

	}
	check = music[0] < music[1] ? 1 : -1;//1이면 오름차순, -1이면 내림차순
	for (int i = 2; i < 8; i++) {
		if ((check == 1 && music[i] < music[i - 1]) || (check == -1 && music[i] > music[i - 1])) {
			cout << "mixed";
			return 0;
		}
		else if (music[i] < music[i - 1]) {
			check = -1;
		}
		else check = 1;
	}
	if (check == 1) cout << "ascending";
	else cout << "descending";
	return 0;
}