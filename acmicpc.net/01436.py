number=int(input())
ans=666
cnt=1
while(cnt<number):
    ans=ans+1
    if str(ans).find('666')!=-1:
        cnt+=1
print(ans)