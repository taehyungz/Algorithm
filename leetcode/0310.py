class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n<2:
            return [0]
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        leaves = []
        for i in range(n):
            if len(graph[i])==1:
                leaves.append(i)
        
        while n>2:
            new_leaves = []
            n = n - len(leaves)
            for lf in leaves:
                lf_next = graph[lf].pop()
                graph[lf_next].remove(lf)
                
                if len(graph[lf_next])==1:
                    new_leaves.append(lf_next)
            leaves = new_leaves
        return leaves
                
                
            