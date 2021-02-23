def solution(numbers):
    ans = ''.join(sorted(map(str, numbers), key=lambda x: (x*3)[:4], reverse = True))
	#x를 4자리로 늘리고, 정렬한다. *3만 하는 이유는 number는 최대 1000이고, 어떤 수라도 *4하면 1000을 넘어서기 때문이다.
    return ans if ans[0]!="0" else "0"