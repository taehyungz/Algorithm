import collections
def solution(bridge_length, weight, truck_weights):
    time = 0
    idx = 0
    on_bridge_weight = 0 #sum �Լ��� ���� �ʰ� �ð����⵵�� ����ϱ� ����
    on_bridge = collections.deque()
    while idx < len(truck_weights):
        while idx<len(truck_weights) and on_bridge_weight+truck_weights[idx]<=weight:
            if on_bridge and time+1>=on_bridge[0][1]: break #�������� �ð��� �� Ʈ���� �ִ�
            time += 1
            on_bridge.append((truck_weights[idx], time+bridge_length))
            on_bridge_weight += truck_weights[idx]
            idx += 1
        truck_info = on_bridge.popleft()
        time = truck_info[1]-1 #�� �ǳʴ� ���ÿ� Ʈ���� �����Ƿ�
        on_bridge_weight -= truck_info[0]
    #���� ������� Ʈ���� ����
    if on_bridge: #�ǳʴ� ���� Ʈ���� �ְ�, �� �迭���� Ʈ���� ������ ������ ���� �ð��� ����Ǿ� ����
        return on_bridge.pop()[1]
    return time+1 #���������� ������ Ʈ���� �����Ƿ�