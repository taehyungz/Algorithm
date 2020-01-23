#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int scores[1000][1000];
queue<char> q;
vector<char> vc;
int main() {
	int R, C;//R은 세로, C는 가로
	int min = 1000;
	int minx, miny;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> scores[i][j];
			if (min > scores[i][j] && (i + j) % 2 == 1) {//체스판처럼 생각했을 때, 흰색으로 시작해서 흰색으로 끝난다.
				//흰색과 검정색의 수는 같으므로, 짝수*짝수의 경우 결국 검정색 하나는 방문하지 못 한다
				min = scores[i][j];
				miny = i;
				minx = j;
			}
		}
	}
	if (R % 2 == 1) {//홀*홀 , 홀*짝
		bool RLcheck = true;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C - 1; j++) {
				if (RLcheck) cout << "R";
				else cout << "L";
			}
			RLcheck = !RLcheck;
			if (i == R - 1) break;
			cout << "D";
		}
	}
	else if (C % 2 == 1) {
		bool UDcheck = true;
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R - 1; j++) {
				if (UDcheck) cout << "D";
				else cout << "U";
			}
			UDcheck = !UDcheck;
			if (i == C - 1) break;
			cout << "R";
		}
	}
	else {
		for (int i = 0; i < miny - 1; i += 2) {
			for (int j = 0; j < C - 1; j++) {
				q.push('R');
			}
			q.push('D');
			for (int j = 0; j < C - 1; j++) {
				q.push('L');
			}
			q.push('D');
		}
		for (int i = R - 1; i > miny + 1; i -= 2) {
			for (int j = C - 2; j >= 0; j--) {
				vc.push_back('R');
			}
			vc.push_back('D');
			for (int j = 0; j < C - 1; j++) {
				vc.push_back('L');
			}
			vc.push_back('D');
		}
		for (int i = 0; i < minx - 1; i += 2) {
			q.push('D');
			q.push('R');
			q.push('U');
			q.push('R');
		}
		if (minx % 2 == 1) {
			q.push('D');
			q.push('R');
		}
		else {
			q.push('R');
			q.push('D');
		}
		for (int i = C - 1; i > minx + 1; i -= 2) {
			q.push('R');
			q.push('U');
			q.push('R');
			q.push('D');
		}
	}
	int qsize = q.size();
	int vcsize = vc.size();
	for (int i = 0; i < qsize; i++) {
		cout << q.front();
		q.pop();
	}
	for (int i = vc.size() - 1; i >= 0; i--) {
		cout << vc[i];
	}
	return 0;
}