class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        start = 0
        used = dict()
        for idx, ch in enumerate(s):
            if ch in used and start<=used[ch]:
                start = used[ch]+1 # continue
            else:
                max_length = max(max_length, idx-start+1)
            used[ch] = idx
        return max_length
                