t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    ans=[]
    for i in range(n):
        curr=a[i]
        best=[a[i],i]
        for j in range(i+1,n-1):
            if best[0]<a[j]:
                best=[a[j],j]
                break
        hold=i
        for j in range(i+1,n):
            if a[j]<best[0] and j > best[1]:
                hold=j
                break
        if best[1]!=i and hold!=i:
            ans.append(i+1)
            ans.append(best[1]+1)
            ans.append(hold+1)
            break
    if len(ans)>0:
        print("YES")
        print(*ans)
    else:
        print("NO")


        
        


