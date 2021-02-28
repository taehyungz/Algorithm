import collections
def solution(cacheSize, cities):
    cache = collections.deque()
    time = 0
    for city in cities:
        city = city.lower()
        if city not in cache and len(cache) != cacheSize: #도시 이름이 캐시에 없고 캐시 꽉 안 참
            time += 5
            cache.append(city)
        elif city in cache: #캐시 꽉 찼고 도시 이름이 캐시에 있음 or 캐시 꽉 안 찼고 도시 이름이 캐시에 있음
            time += 1
            cache.remove(city)
            cache.append(city)            
        elif cacheSize and city not in cache: #캐시 꽉 찼고 도시 이름이 캐시에 없음
            time += 5
            cache.popleft()
            cache.append(city)
        else: #캐시사이즈가 0
            time += 5
    return time