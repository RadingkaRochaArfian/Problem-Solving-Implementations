from collections import defaultdict


n,m=map(int,input().split())
servers=defaultdict(list)
for _ in range(n):
    a,b=input().split()
    servers[b].append(a)
for _ in range(m):
    a,b=input().split()
    ip=b[:-1]
    print(f"{a} {b} #{servers[ip][0]}")
