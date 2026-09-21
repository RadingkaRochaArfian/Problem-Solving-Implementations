n=int(input())
a=[0]+list(map(int,input().split(' ')))
ans=[]
for i in range(1,n+1):
    visited=set()
    while i not in visited:
        visited.add(i)
        i=a[i]
    print(i,end=' ')