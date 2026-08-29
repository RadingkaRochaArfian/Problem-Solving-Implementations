t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    ans=1
    streak=0
    arr=set(arr)
    arr=list(arr)
    arr.sort()
    n=len(arr)
    for i in range(n):
        if i==0 or arr[i]-arr[i-1]>1:
            streak = 0
        streak += 1
        ans = max(ans, streak)
    print(ans)