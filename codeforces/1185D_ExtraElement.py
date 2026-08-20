import sys


n=int(input())
a=list(map(int,input().split()))
arr=[(a[i],i)for i in range(n)]
if n==2:
    print(1)
    sys.exit()
arr.sort()
check=True
diff=arr[2][0]-arr[1][0]
for i in range(2,n-1):
    check&=(arr[i+1][0]-arr[i][0])==diff
if check:
    print(arr[0][1]+1)
    sys.exit()
check=True
diff=arr[2][0]-arr[0][0]
for i in range(2,n-1):
    check&=(arr[i+1][0]-arr[i][0])==diff
if check:
    print(arr[1][1]+1)
    sys.exit()
diff=arr[1][0]-arr[0][0]
check=False
i=1
ans=1
while i<(n-1):
    if arr[i+1][0]-arr[i][0]==diff:
        i+=1
        continue
    if check:
        print(-1)
        sys.exit()
    if i==n-2:
        print(arr[i+1][1]+1)
        sys.exit()
    if arr[i+2][0]-arr[i][0]==diff:
        ans=arr[i+1][1]+1
        check=True
        i+=2
    else:
        print(-1)
        sys.exit()
    i+=1
print(ans)
