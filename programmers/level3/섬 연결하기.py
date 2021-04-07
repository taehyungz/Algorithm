def solution(n, costs):
    def get_parent(node):
        if parent[node] != node: parent[node] = get_parent(parent[node])
        return parent[node]
    
    def union(u,v):
        p1 = get_parent(u)
        p2 = get_parent(v)
        parent[p2] = p1
    
    parent = [i for i in range(n)]
    costs.sort(key = lambda x: -x[2])
    
    total_cost = 0
    cnt = 0
    while costs:
        u, v, cost = costs.pop()
        if get_parent(u) != get_parent(v):
            union(u,v)
            cnt+=1
            total_cost += cost
        if cnt==n-1: return total_cost