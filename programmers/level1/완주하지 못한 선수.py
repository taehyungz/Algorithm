def solution(new_id):
    ans = ""
    for ch in new_id.lower():
        if ch.isdigit() or ch.isalpha() or ch in ['-','_','.']:
            if len(ans)>0 and ans[-1]=="." and ch==".": continue
            ans+=ch
    if ans.startswith("."): ans = ans[1:]
    if ans.endswith("."): ans = ans[:-1]
    if ans=="": ans="a"
    if len(ans)>=16: ans=ans[:15]
    if ans[-1]==".": ans = ans[:14]
    if len(ans)<=2:
        need = 3-len(ans)
        ans += ans[-1]*need
    return ans