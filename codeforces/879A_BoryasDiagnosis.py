n=int(input())
a,b=map(int,input().split())
arr= [a]
for _ in range(1,n):
    a,b=map(int,input().split())
    while a<=arr[-1]:
        a+=b
    arr.append(a)
print(arr[-1])