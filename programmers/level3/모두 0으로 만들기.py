import collections

def solution(a, edges):
    graph = collections.defaultdict(list)
    leaf_del_count = collections.defaultdict(int)
    for edge in edges:
        graph[edge[0]].append(edge[1])
        graph[edge[1]].append(edge[0])
    leaf = collections.deque()
    visited = [False for _ in range(len(a))]
    total = 0

    for node in range(len(a)):
        total += a[node]
        if len(graph[node]) == 1:
            leaf.append(node)
    if total != 0: return -1

    ans = 0
    while leaf:
        node = leaf.popleft()
        visited[node] = True
        for next_node in graph[node]:
			# leaf_del_count에 해당 노드에서 지운 간선 개수를 저장하고, 원래 간선 개수와 빼서 1이면 leaf라고 판단
            # graph[next_node].remove(node)
            leaf_del_count[next_node] += 1
            if not visited[next_node]:
                if len(graph[next_node]) - leaf_del_count[next_node] == 1: leaf.append(next_node)
                if a[node]==0: continue
                ans += abs(a[node])
                a[next_node] += a[node]
                a[node] = 0
    return ans