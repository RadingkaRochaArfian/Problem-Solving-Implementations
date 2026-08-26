


from math import gcd


t=int(input())
for _ in range(t):
    a,b,k = map(int,input().split())
    ans=2
    x=gcd(a,b)
    if a//x<=k and b//x<=k:
        ans=1
    print(ans)

