from collections import defaultdict
import sys
n,x = map(int, input().split())
arr = list(map(int, input().split()))
mp=defaultdict(int)
for c in arr:
    mp[c]+=1
for c in mp:
    if mp[c]>=2:
        print(0)
        sys.exit()
for i in range(n):
    num=arr[i]&x
    if mp[num]>0 and num!=arr[i]:
        print(1)
        sys.exit()//test
cnt=0
mp=defaultdict(int)
for c in arr:
    num=c&x
    mp[num]+=1
for c in mp:
    if mp[c]>=2:
        print(2)
        sys.exit()
print(-1)

