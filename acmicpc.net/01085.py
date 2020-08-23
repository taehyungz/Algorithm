x, y, w, h = map(int, input().split())
print(min(min(min(y,w-x),x),h-y))