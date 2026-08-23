t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    level=1e9
    psum=0
    for i in range(n):
        psum+=arr[i]
        mean=psum//(i+1)
        level=min(level,mean)
        print(level,end=" ")
    print("")
