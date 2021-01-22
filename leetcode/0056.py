class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key = lambda x: x[0])
        
        ans = [intervals[0]]
        for i in range(1,len(intervals)):
            if ans[-1][1] >= intervals[i][0]:
                a = ans[-1][0]
                b = max(ans[-1][1], intervals[i][1])
                ans.pop()
                ans.append([a, b])
            else:
                ans.append(intervals[i])
        return ans