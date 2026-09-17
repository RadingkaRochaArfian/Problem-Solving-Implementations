t=int(input())
for _ in range(t):
    n,k=map(int,input().split(" "))
    left=0
    right=50
    for _ in range(n):
        l,r=map(int,input().split())
        if k>=l and k<=r:
            left=max(left,l)
            right=min(right,r)
    if left==right:
        print('YES')
    else:
        print('NO')