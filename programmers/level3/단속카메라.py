def solution(routes):
    routes.sort(key=lambda x: -x[1])
    print(routes)
    idx = len(routes)-1
    last_out = routes[idx][1]
    ans = 0
    while idx>=0:
        if routes[idx][0] <= last_out:
            idx -= 1
            continue
        ans += 1
        last_out = routes[idx][1]
        idx -= 1
    return ans+1