#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Info_Mem {
private:
	int age;
	string name;
public:
	Info_Mem(const int &ipage, const string &ipname) : age(ipage), name(ipname) {}
	int getAge() { return age; }
	string getName() { return name; };
};
bool cmp(Info_Mem a, Info_Mem b) {
	return a.getAge() < b.getAge();
}

int main() {
	int N;
	cin >> N;
	vector<Info_Mem> vc;
	int age;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		Info_Mem *im = new Info_Mem(age, name);
		vc.push_back(*im);
	}
	stable_sort(vc.begin(), vc.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << vc[i].getAge() << ' ' << vc[i].getName() << '\n';
	}
	return 0;
}