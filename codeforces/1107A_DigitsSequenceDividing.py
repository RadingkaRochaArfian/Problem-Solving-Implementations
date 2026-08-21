t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    arr=list(s)
    same=True
    curr=s[0]
    if n==2 and arr[1]<=arr[0]:
        print("NO")
        continue
    i=1
    while i<n:
        if s[i]!=curr:
            same=False
            break
        i+=1
    print("YES")
    print(2)
    print(arr[0],end=" ")
    for i in range(1,n):
        print(arr[i],end="")
    print("")
