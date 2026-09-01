t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    same=len(set(a))==1
    if same:
        print(-1)
        continue
    best=[a[0],0]
    for i in range(1,n):
        if a[i]>=best[0] and (i>0 and a[i-1]<a[i] or i<n-1 and a[i+1]<a[i]):
            best=[a[i],i]
    print(best[1]+1)
