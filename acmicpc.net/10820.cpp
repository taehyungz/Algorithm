#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int counts[4];
int main() {
	string str;
	for (int j = 0; j < 100; j++) {
		getline(cin, str);
		if (str.length() == 0) break;
		memset(&counts[0], 0, sizeof(counts));
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z') counts[0]++;
			else if (str[i] >= 'A' && str[i] <= 'Z') counts[1]++;
			else if (str[i] >= '0' && str[i] <= '9') counts[2]++;
			else counts[3]++;
		}
		for (int i = 0; i < 4; i++) {
			cout << counts[i] << ' ';
		}
		cout << '\n';
	}
}