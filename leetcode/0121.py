class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0 : return 0
        min_point = prices[0]
        max_profit = 0
        for i in range(len(prices)):
            min_point = min(min_point, prices[i])
            max_profit = max(max_profit, prices[i] - min_point)
        
        return max_profit