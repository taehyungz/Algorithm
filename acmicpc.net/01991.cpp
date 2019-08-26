#include <iostream>
using namespace std;
int arr[26][2];

void Preorder(int n) {
	if (n == -1) return;
	cout << (char)(n + 'A');
	Preorder(arr[n][0]);
	Preorder(arr[n][1]);
}
void Inorder(int n) {
	if (n == -1) return;
	Inorder(arr[n][0]);
	cout << (char)(n + 'A');
	Inorder(arr[n][1]);
}
void Postorder(int n) {
	if (n == -1) return;
	Postorder(arr[n][0]);
	Postorder(arr[n][1]);
	cout << (char)(n + 'A');
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A';
		y = y != '.' ? y - 'A' : -1;
		z = z != '.' ? z - 'A' : -1;
		arr[x][0] = y;
		arr[x][1] = z;
	}
	Preorder(0); cout << '\n';
	Inorder(0); cout << '\n';
	Postorder(0); cout << '\n';
}