#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
private:
	string name;
	int kor;
	int math;
	int eng;
public:
	Student(string str, int a, int b, int c) : name(str), kor(a), eng(b), math(c) {}
	string getName() { return name; }
	int getKor() { return kor; }
	int getMath() { return math; }
	int getEng() { return eng; }
};

bool cmp(Student a, Student b) {
	if (a.getKor() > b.getKor()) return true;
	else if (a.getKor() < b.getKor()) return false;
	else if (a.getEng() < b.getEng()) return true;
	else if (a.getEng() > b.getEng()) return false;
	else if (a.getMath() > b.getMath()) return true;
	else if (a.getMath() < b.getMath()) return false;
	else if (a.getName().compare(b.getName()) < 0) return true;
	else return false;
}

int main() {
	vector <Student> students;
	int N;
	cin >> N;
	int a, b, c;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str >> a >> b >> c;
		students.push_back(Student(str, a, b, c));
	}
	sort(students.begin(), students.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << students[i].getName() << '\n';
	}
	return 0;
}