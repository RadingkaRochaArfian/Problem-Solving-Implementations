import sys


n=int(input())
a=[]
b=[]
for _ in range(n):
    l,r,p=map(int,input().split(' '))
    a.append([l,r])
    b.append=p
ans=0
if n==1:
    print(1)
    sys.exit()
for i in range(n-1):
    if i==0 and n>1:
        if a[i+1][0]-a[i][1]>=b[i]:
            ans+=1
    else:
        front=a[i+1][0]
        rear=a[i-1][1]
        if a[i][0]-rear>=b[i] and a[i][1]-front>=b:
            ans+=1