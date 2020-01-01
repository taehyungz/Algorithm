#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string temp = "";
	vector<int> numbers;
	vector<char> pm;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
		}
		else {
			numbers.push_back(stoi(temp));
			temp = "";
			pm.push_back(s[i]);
		}
	}
	numbers.push_back(stoi(temp));//숫자, 기호 저장 완료
	int tempnum = 0;//-가 나왔을 때 다음 -가 나오기 전까지의 숫자 합을 저장하는 변수
	int pmcnt = 0;//기호들을 저장한 벡터에서의 인덱스
	int sum = numbers[0];//초깃값
	for (int i = 1; i < numbers.size(); i++) {
		if (pm[pmcnt] == '-') {//-이면
			do {//do while 쓴 이유는 -이후가 없을 수도 있기 때문에
				tempnum += numbers[i++];
				pmcnt++;
			} while (pmcnt < pm.size() && pm[pmcnt] == '+');//pmcnt가 pm의 크기를 넘지 않고 pm[pmcnt]가 더하기 이면 반복
			i--;//for문에서 i를 올려주므로 하나 내림
			sum -= tempnum;
		}
		else {
			pmcnt++;
			tempnum = numbers[i];
			sum += tempnum;
		}
		tempnum = 0;//tempnum 초기화
	}
	cout << sum;
	return 0;
}