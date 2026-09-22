t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    a=[]
    for i in range(n):
        a.append(list(map(int,input().split())))
    vis=set()
    ans=0
    def dfs(i,j):
        stack=[(i,j)]
        vis.add((i,j))
        total=0
        dir=[(-1,0),(1,0),(0,-1),(0,1)]
        while stack:
            i,j=stack.pop()
            total+=a[i][j]
            for di,dj in dir:
                ni,nj=i-di,j-dj
                if 0<=ni<n and 0<=nj<m:
                    if (ni,nj) not in vis and a[ni][nj]!=0:
                        vis.add((ni,nj))
                        stack.append((ni,nj))
        return total
    for i in range(n):
        for j in range(m):
            if (i,j) not in vis and a[i][j]!=0:
                ans=max(ans,dfs(i,j))
    print(ans)
