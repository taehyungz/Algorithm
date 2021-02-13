class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        def compute(left, right, op):
            results = []
            for l in left:
                for r in right:
                    results.append(eval(str(l)+op+str(r)))
            return results
        
        if input.isdigit():
            return [int(input)]
        
        results = []
        for idx, value in enumerate(input):
            if value in "-+*":
                left = self.diffWaysToCompute(input[:idx])
                right = self.diffWaysToCompute(input[idx+1:])
                results.extend(compute(left, right, value))
        return results