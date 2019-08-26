#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int x, y;
	int days = 0;

	cin >> x >> y;
	for (int i = 1; i < x; i++) {
		if ((i % 2 == 1 && i < 8) || (i % 2 == 0 && i > 7)) days += 31;
		else if (i == 2) days += 28;
		else days += 30;
	}
	days += y - 1;
	days = days % 7;
	switch (days) {
	case 0: cout << "MON"; break;
	case 1: cout << "TUE"; break;
	case 2: cout << "WED"; break;
	case 3: cout << "THU"; break;
	case 4: cout << "FRI"; break;
	case 5: cout << "SAT"; break;
	case 6: cout << "SUN";
	}
	return 0;
}