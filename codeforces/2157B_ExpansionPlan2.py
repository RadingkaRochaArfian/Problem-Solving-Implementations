t=int(input())
for _ in range(t):
    n,x,y=map(int,input().split())
    x=abs(x)
    y=abs(y)
    s=input()
    val=x+y
    cnt=0
    for c in s:
        if c=='4':
            cnt+=1
        else:
            cnt+=2
    ans="NO"
    if cnt>=val and n >= max(x,y):
        ans="YES"
    print(ans)