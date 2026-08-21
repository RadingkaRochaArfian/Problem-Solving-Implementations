t=int(input())
for _ in range(t):
    n,m,k=map(int,input().split())
    print(n,end=" ")
    second=1
    for i in range(1,n):
        num=n-i
        if num <=m:
            second=num
            break
        print(num,end=" ")
    for i in range(1,second+1):
        print(i,end=" ")
    print("")
