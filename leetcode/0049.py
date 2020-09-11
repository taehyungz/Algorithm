import collections
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        df_dict = collections.defaultdict(list)
        for word in strs:
            df_dict[''.join(sorted(word))].append(word)
        return df_dict.values()