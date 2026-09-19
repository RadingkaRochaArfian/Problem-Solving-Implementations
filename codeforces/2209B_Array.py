t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split(' ')))
    for i in range(n):
        ans1=0
        for j in range(i+1,n):
            if a[i]<a[j]:
                ans1+=1
        ans2=0
        for j in range(i+1,n):
            if a[i]>a[j]:
                ans2+=1
        ans=max(ans1,ans2)
        print(ans,end=' ')
    print()