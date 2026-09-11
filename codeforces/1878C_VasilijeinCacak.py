t=int(input())
for _ in range(t):
    n,k,x=map(int,input().split())
    sum1=k*(k+1)
    sum2=n*(n+1)-(n-k)*(n-k+1)
    if sum1 <=2*x and 2*x <=sum2 :
        print("YES")
    else:
        print("NO")
