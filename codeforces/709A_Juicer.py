n,b,d=map(int,input().split())
arr=list(map(int,input().split()))
sum=0
cnt=0
for x in arr:
    if x>b:
        continue
    sum+=x
    if sum>d:
        cnt+=1
        sum=0
print(cnt)
