import collections
def solution(bridge_length, weight, truck_weights):
    time = 0
    idx = 0
    on_bridge_weight = 0 #sum 함수를 쓰지 않고 시간복잡도를 향상하기 위해
    on_bridge = collections.deque()
    while idx < len(truck_weights):
        while idx<len(truck_weights) and on_bridge_weight+truck_weights[idx]<=weight:
            if on_bridge and time+1>=on_bridge[0][1]: break #빠져나갈 시간이 된 트럭이 있다
            time += 1
            on_bridge.append((truck_weights[idx], time+bridge_length))
            on_bridge_weight += truck_weights[idx]
            idx += 1
        truck_info = on_bridge.popleft()
        time = truck_info[1]-1 #다 건너는 동시에 트럭이 들어오므로
        on_bridge_weight -= truck_info[0]
    #이제 대기중인 트럭은 없다
    if on_bridge: #건너는 중인 트럭이 있고, 이 배열에는 트럭이 완전히 지났을 때의 시간이 저장되어 있음
        return on_bridge.pop()[1]
    return time+1 #마지막에는 들어오는 트럭이 없으므로