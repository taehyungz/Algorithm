import collections
num = int(input())

ls = [i for i in range(1,num+1)]
deque = collections.deque(ls)
while len(deque)>2:
    deque.popleft()
    temp = deque[0]
    deque.popleft()
    deque.append(temp)
if len(deque)==1:
    print(deque[0])
else:
    deque.popleft()
    print(deque[0])