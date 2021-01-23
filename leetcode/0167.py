class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        dt = collections.defaultdict(int)
        for i, n in enumerate(numbers):
            dt[n] = i+1
            
        for i, n in enumerate(numbers):
            if dt[target-n] != i+1 and dt[target-n] != 0:
                return [i+1, dt[target-n]]