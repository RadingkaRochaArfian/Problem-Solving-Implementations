t =int(input())
for _ in range(t):
    n =int(input())
    a= list(map(int,input().split()))
    mx=a[0]
    for i in range(1,n-1):
        mx=max(mx,a[i])
    if mx==0:
        print(0)
        continue
    zeroCnt=a.count(0)
    exclude=0
    for i in range(n-1):
        if a[i]==0:
            exclude+=1
        elif a[i]>0:
            break
    zeroCnt-=exclude
    if a[-1]==0:
        zeroCnt-=1
    cnt=sum(a)+zeroCnt
    cnt-=a[-1]
    print(cnt)