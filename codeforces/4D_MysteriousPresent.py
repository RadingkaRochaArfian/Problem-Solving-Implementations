import sys


n,w,h=map(int,input().split())
arr:list[tuple[int,int,int]]=[]
for i in range(1,n+1):
    a,b =map(int,input().split())
    if a>w and b>h:
        arr.append((a,b,i))
if not arr:
    print(0)
    sys.exit()
m=len(arr)
arr.sort(key=lambda x:(x[0],x[1]))
bestIdx=0
dp=[1]*m
parent=[-1]*m
for i in range(m):
    for j in range(i):
        if arr[j][0]>=arr[i][0] or arr[j][1]>=arr[i][1]:
            continue
        if dp[j]+1>dp[i]:
            dp[i]=dp[j]+1
            parent[i]=j
    if dp[i]>dp[bestIdx]:
        bestIdx=i
ans:list[int]=[]
curr=bestIdx
while curr!=-1:
    ans.append(arr[curr][2])
    curr=parent[curr]
ans.reverse()
print(len(ans))
for id in ans:
    print(id,end=" ")
print("")

        
