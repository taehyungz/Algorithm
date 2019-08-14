#include <iostream>
using namespace std;

int GCD(int numa, int numb) {
	if (numb == 0) return numa;
	else return GCD(numb, numa%numb);
}

int main() {
	ios_base::sync_with_stdio(false);
	int numa, numb;
	cin >> numa >> numb;
	cout << GCD(numa, numb) << '\n';
	cout << numa * numb / GCD(numa, numb);
	return 0;
}