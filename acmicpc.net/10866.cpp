#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
	int data;
	Node* prev;
	Node* next;
	Node* newNode(int data) {
		Node* new_node = new Node();
		new_node->data = data;
		new_node->prev = NULL;
		new_node->next = NULL;
		return new_node;
	}
} node;
typedef struct Deque {
	node* fr;
	node* ba;
	int dq_size;
public:
	Deque() {
		fr = NULL;
		ba = NULL;
		dq_size = 0;
	}
	void push_front(int X) {
		if (size() == 0) {
			Node* nd = new Node();
			fr = nd;
			ba = nd;
			nd->data = X;
		}
		else {
			Node* nd = fr->newNode(X);
			nd->next = fr;
			fr->prev = nd;
			fr = nd;
		}
		dq_size++;
	}
	void push_back(int X) {
		if (size() == 0) {
			Node* nd = new Node();
			fr = nd;
			ba = nd;
			nd->data = X;
		}
		else {
			Node* nd = ba->newNode(X);
			nd->prev = ba;
			ba->next = nd;
			ba = nd;
		}
		dq_size++;
	}
	void pop_front() {
		if (size() == 0) cout << -1 << '\n';
		else {
			cout << fr->data << '\n';
			Node* nd = fr;
			fr = fr->next;
			delete nd;
			dq_size--;
		}
	}
	void pop_back() {
		if (size() == 0) cout << -1 << '\n';
		else {
			cout << ba->data << '\n';
			Node* nd = ba;
			ba = ba->prev;
			delete nd;
			dq_size--;
		}
	}
	int size() {
		return dq_size;
	}
	int empty() {
		return (size() == 0 ? 1 : 0);
	}
	int front() {
		if (size() == 0) return -1;
		return fr->data;
	}
	int back() {
		if (size() == 0) return -1;
		return ba->data;
	}
} deque;
int main() {
	Deque dq;
	int N;
	string s;
	cin >> N;
	while (N--) {
		cin >> s;
		if (s == "push_front") {
			int temp;
			cin >> temp;
			dq.push_front(temp);
		}
		else if (s == "push_back") {
			int temp;
			cin >> temp;
			dq.push_back(temp);
		}
		else if (s == "pop_front") {
			dq.pop_front();
		}
		else if (s == "pop_back") {
			dq.pop_back();
		}
		else if (s == "size") cout << dq.size() << '\n';
		else if (s == "empty") cout << dq.empty() << '\n';
		else if (s == "front") cout << dq.front() << '\n';
		else cout << dq.back() << '\n';
	}
}