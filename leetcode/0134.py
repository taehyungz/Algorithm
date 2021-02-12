class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas)<sum(cost): return -1
        start = [i for i in range(len(gas)) if gas[i]>=cost[i]]
        for st in start:
            p_gas = 0
            flag = True
            for i in range(len(gas)):
                pos = (st+i)%len(gas)
                p_gas = p_gas + gas[pos] - cost[pos]
                if p_gas<0:
                    flag = False
                    break
            if flag==True:
                return st
        return -1