

t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    exp=0
    for i in range(n):
        if arr[i]%2==0:
            trz=(arr[i]&-arr[i]).bit_length()-1
            exp+=trz
            arr[i]>>=trz
    arr.sort()
    arr[-1]<<=exp
    print(sum(arr))
    
            
