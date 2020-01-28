#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K, cnt;
	cin >> N >> K;
	cnt = N - K;
	vector<int> vc;
	vector<int> ans;
	int temp;
	scanf("%1d", &temp);
	vc.push_back(temp);
	for (int i = 1; i < N; i++) {
		scanf("%1d", &temp);
		while (K && vc.size() > 0 && vc.back() < temp) {
			//지워야 할 것이 남아있고, 지울 것이 있으며, 앞의 수가 이후 수보다 작으면 앞의 수를 지우고 이후 수를 넣음
			vc.pop_back();
			K--;
		}
		vc.push_back(temp);
	}
	for (int i = 0; i < cnt; i++) {
		cout << vc[i];
	}
}