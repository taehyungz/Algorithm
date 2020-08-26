#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ground;
vector<int> height;
int main() {
	int N, M, B;
	int maxh = 0;
	int minh = 257;
	int min_needtime = INT32_MAX;
	int max_height = 0;
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		vector<int> vc_temp;
		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;
			maxh = maxh < n ? n : maxh;
			minh = minh > n ? n : minh;
			vc_temp.push_back(n);
		}
		ground.push_back(vc_temp);
	}

	for (int cal_h = minh; cal_h <= maxh; cal_h++) {
		int need_block = 0;
		int need_time = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ground[i][j] > cal_h) {
					need_time = need_time + (ground[i][j] - cal_h) * 2;
					need_block = need_block - (ground[i][j] - cal_h);
				}
				else if (ground[i][j] < cal_h) {
					need_time = need_time + (cal_h - ground[i][j]);
					need_block = need_block + (cal_h - ground[i][j]);
				}
			}
		}
		if (need_block > B) continue;
		if (min_needtime < need_time) continue;
		if (min_needtime > need_time) {
			height.clear();
			min_needtime = need_time;
		}
		max_height = max_height < cal_h ? cal_h : max_height;
	}
	printf("%d %d", min_needtime, max_height);
}