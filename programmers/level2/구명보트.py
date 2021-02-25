import collections
def solution(people, limit):
    people = collections.deque(sorted(people))
    weight = 0
    boat = 0
    while people:
        while people and weight+people[-1]<=limit:
            weight += people.pop()
        while people and weight+people[0]<=limit:
            weight += people.popleft()
        boat += 1
        weight = 0
    return boat