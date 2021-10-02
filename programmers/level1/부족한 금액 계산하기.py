def solution(price, money, count):
    ride_cnt = 1
    while count > 0:
        money -= price * ride_cnt
        count, ride_cnt = count-1, ride_cnt+1
    if money > 0: return 0
    else: return -money