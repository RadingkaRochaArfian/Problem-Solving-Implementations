n=int(input())
arr=list(map(int,input().split()))
mid=n//2
for i in range (mid):
    if i%2==0:
        arr[i],arr[n-i-1]=arr[n-1-i],arr[i]
for x in arr:
    print(x,end=' ')
print()