#include <iostream>
#include <vector>
using namespace std;
vector<char> vc;
int main() {
	int T;
	cin >> T;
	getchar();
	while (T--) {
		while (1) {
			char ch;
			scanf("%1c", &ch);
			vc.push_back(ch);
			if (ch == ' ') {
				for (int i = vc.size() - 2; i >= 0; i--) {
					cout << vc[i];
				}
				cout << ' ';
				vc.clear();
			}
			else if (ch == '\n') {
				for (int i = vc.size() - 2; i >= 0; i--) {
					cout << vc[i];
				}
				cout << '\n';
				vc.clear();
				break;
			}
		}
	}
}