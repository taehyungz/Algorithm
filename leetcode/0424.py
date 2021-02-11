class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if not s: return 0
        left = right = 0
        counts = collections.Counter()
        
        for right in range(len(s)):
            counts[s[right]] += 1
            
            max_char_n = counts.most_common(1)[0][1]
            
            if right + 1 - left - max_char_n > k:
                counts[s[left]] -= 1
                left += 1
        return right-left+1