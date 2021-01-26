class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        num = bin(x^y)
        return num.count('1')