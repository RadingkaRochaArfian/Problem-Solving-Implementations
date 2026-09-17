n=int(input())
best=0
for _ in range(n):
    x,y=map(int,input().split(' '))
    best=max(best,x+y)
print(best)