import sys


n=int(input())
arr:list[list[int]]=[]
for _ in range(n):
    a,b=map(int,(input().split()))
    arr.append([a,b])
diff=False
for a,b in arr:
    if a !=b:
        diff=True
        break
if diff:
    print("rated")
    sys.exit()
Inc=False
for i in range(n-1):
    if arr[i][0]<arr[i+1][0]:
        Inc=True
        break
if Inc:
    print("unrated")
else:
    print("maybe")
