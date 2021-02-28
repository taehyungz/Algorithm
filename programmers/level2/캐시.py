import collections
def solution(cacheSize, cities):
    cache = collections.deque()
    time = 0
    for city in cities:
        city = city.lower()
        if city not in cache and len(cache) != cacheSize: #���� �̸��� ĳ�ÿ� ���� ĳ�� �� �� ��
            time += 5
            cache.append(city)
        elif city in cache: #ĳ�� �� á�� ���� �̸��� ĳ�ÿ� ���� or ĳ�� �� �� á�� ���� �̸��� ĳ�ÿ� ����
            time += 1
            cache.remove(city)
            cache.append(city)            
        elif cacheSize and city not in cache: #ĳ�� �� á�� ���� �̸��� ĳ�ÿ� ����
            time += 5
            cache.popleft()
            cache.append(city)
        else: #ĳ�û���� 0
            time += 5
    return time