t= int(input())
for _ in range(t):
    a,b,c,r = map(int,input().split())
    a,b=max(a,b),min(a,b)
    up=c+r
    down=c-r
    dist=a-b
    left=min(up,a)
    right=max(down,b)
    ans=dist-max(0,left-right)
    print(ans)