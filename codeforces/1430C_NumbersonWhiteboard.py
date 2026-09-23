t=int(input())
for _ in range(t):
    n=int(input())
    print(2)
    a,b=n,n-1
    print(a,b)
    last=(a+b+1)//2
    for i in range(n-2,0,-1):
        print(last,i)
        last=(last+i+1)//2