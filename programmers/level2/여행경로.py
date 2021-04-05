import collections

def solution(tickets):
    def dfs(origin):
        while dic[origin]:
            dfs(dic[origin].pop())
        answer.append(origin)

    dic = collections.defaultdict(list)
    for ticket in sorted(tickets, reverse=True):
        dic[ticket[0]].append(ticket[1])
    answer = []
    dfs("ICN")
    return answer[::-1]