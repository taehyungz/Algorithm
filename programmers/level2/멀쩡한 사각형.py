import math

def solution(w,h):
    def get_gcd(a, b):
        if b==0: return a
        return get_gcd(b, a%b)
    
    if w == h: return w*h - w
    elif w == 1 or h == 1: return 0
    
    gcd = get_gcd(w, h) if w>=h else get_gcd(h, w)
    mini_w, mini_h = w//gcd, h//gcd
    leaning = mini_h/mini_w
    cnt = 0
    for x in range(mini_w):
        cnt += math.ceil(leaning*(x+1)) - math.floor(leaning*x)
    return w * h - cnt * gcd