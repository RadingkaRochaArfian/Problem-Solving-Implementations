k,m,n=map(int,input().split(' '))
a=[]
for i in range(k*m):
    arr=list(map(int,input().split(' ')))
    for j in range(n):
        a.append(arr[j])
a.sort()
idx=0
while idx!=len(a):
    for i in range(m):
        for j in range(n):
            print(a[idx],end=' ')
            idx+=1
        print()
    print()