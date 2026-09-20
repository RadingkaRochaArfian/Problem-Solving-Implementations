from collections import deque
import sys


n,s=map(int,input().split(' '))
a=[0]+list(map(int,input().split(' ')))
b=[0]+list(map(int,input().split(" ")))
start=(1,1)
queue=deque([start])
visited={start}
if a[1]==0:
    print('NO')
    sys.exit()
while queue:
    node=queue.popleft()
    if node[0]==s:
        print('YES')
        sys.exit()
    if node[1]==1:
        for i in range(node[0]+1,n+1):
            if a[i]==1:
                state=(i,1)
                if state not in visited:
                    visited.add(state)
                    queue.append(state)
    else:
        for i in range(node[0]-1,0,-1):
            if b[i]==1:
                state=(i,2)
                if state not in visited:
                    visited.add(state)
                    queue.append(state)
    if a[node[0]]==1 and b[node[0]]==1:
        state=(node[0],3-node[1])
        if state not in visited:
            visited.add(state)
            queue.append(state)
print('NO')