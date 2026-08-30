t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    mx=a[-1]
    ans=0
    for i in range(n-2,-1,-1):
        if a[i]>mx:
            ans+=1
            mx=a[i]
    print(ans)