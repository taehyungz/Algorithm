class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).zfill(32).count('1')