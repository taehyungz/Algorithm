def solution(numbers):
    ans = ''.join(sorted(map(str, numbers), key=lambda x: (x*3)[:4], reverse = True))
	#x�� 4�ڸ��� �ø���, �����Ѵ�. *3�� �ϴ� ������ number�� �ִ� 1000�̰�, � ���� *4�ϸ� 1000�� �Ѿ�� �����̴�.
    return ans if ans[0]!="0" else "0"