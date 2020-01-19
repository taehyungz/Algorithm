#include <iostream>
#include <vector>
using namespace std;
vector<char> op;
vector<int> numbers;
int main() {
	int sum = 0;
	while (1) {
		char ch = getchar();
		if (ch == '\n') {
			numbers.push_back(sum);
			break;
		}
		else if (ch >= '0' && ch <= '9') {
			sum *= 10;
			sum = sum + ch - '0';
		}
		else {
			numbers.push_back(sum);
			sum = 0;
			op.push_back(ch);
		}
	}//숫자, 기호 저장 완료
	sum = numbers[0];
	int subsum = 0;
	for (int i = 1, j = 0; i < numbers.size(); i++) {
		if (op[j] == '-') {//기호가 -이면
			subsum = numbers[i++];
			j++;
			while (j < op.size() && op[j++] != '-') {//다음 마이너스가 나올때까지 subsum에 합함
				subsum += numbers[i++];
			}
			i--;
			j--;//위 while문제서 i와 j가 1씩 더해져서 완료됐으므로 빼줌
			sum -= subsum;//-의 서브썸이였으므로 빼줌
			subsum = 0;//subsum 초기화
		}
		else {
			sum += numbers[i];
			j++;
		}
	}
	cout << sum;
	return 0;
}