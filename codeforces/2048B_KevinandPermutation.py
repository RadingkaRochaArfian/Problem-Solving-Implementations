t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    i=0
    mn=1
    sub=0
    while i<n:
        for _ in range(k-1):
            if i>=n:
                break
            print(n-sub,end=" ")
            sub+=1
            i+=1
        if i>=n:
            break
        print(mn,end=" ")
        mn+=1
        i+=1
    print("")
