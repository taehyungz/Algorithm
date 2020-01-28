#include <iostream>
#include <string>
using namespace std;

typedef struct Queue {
	int arr[10000];
	int fr = 0;
	int ba = 0;
	void push(int num) {
		arr[ba++] = num;
	}
	void pop() {
		if (fr == ba) cout << -1 << '\n';
		else {
			cout << arr[fr] << '\n';
			fr++;
		}
	}
	int size() {
		return ba - fr;
	}
	int empty() {
		return (ba - fr > 0 ? 0 : 1);
	}
	int front() {
		if (fr == ba) return -1;
		return arr[fr];
	}
	int back() {
		if (fr == ba) return -1;
		return arr[ba - 1];
	}
} queue;

int main() {
	int N;
	queue q;
	string s;
	cin >> N;
	while (N--) {
		cin >> s;
		if (s == "push") {
			int temp;
			cin >> temp;
			q.push(temp);
		}
		else if (s == "front") {
			if (q.size() == 0) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (s == "back") {
			if (q.size() == 0) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
		else if (s == "size") cout << q.size() << '\n';
		else if (s == "empty") cout << q.empty() << '\n';
		else if (s == "pop") q.pop();
	}
}