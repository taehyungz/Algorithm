def solution(n, m):
    def get_gcd(small, big):
        if small==big: return small
        return get_gcd(big-small, small) if big-small<=small else get_gcd(small, big-small)
    n, m = min(n,m),max(n,m)
    gcd = get_gcd(n,m)
    return[gcd, n//gcd*m ]