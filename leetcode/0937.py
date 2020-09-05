class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digits = []
        strs = []
        for log in logs:
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                strs.append(log)
        strs.sort(key = lambda x: (x.split()[1:],x.split()[0]))
        return strs+digits