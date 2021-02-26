def solution(arr):
    #최대공약수를 구한 후, 최소공배수를 구한다
    def get_gcd(num1, num2):
        if num2==0: return num1
        return get_gcd(num2, num1%num2) if num2<num1 else get_gcd(num1, num2%num1)
    
    if len(arr)==1: return arr[0]
    arr = sorted(arr)
    gob = arr[0]
    for i in range(len(arr)-1):
        temp_gcd = get_gcd(arr[i], arr[i+1]) if arr[i]<arr[i+1] else get_gcd(arr[i+1], arr[i])
        arr[i+1] *= arr[i]//temp_gcd
    return arr[-1]