a=[[1]*3 for _ in range(3)]
for i in range(3):
    s =input().split(" ")
    for j in range(3):
        x=int(s[j])
        if(x%2==1):
            if(i-1>=0):
                y=a[i-1][j]=1-a[i-1][j]
            if(j-1>=0):
                a[i][j-1]=1-a[i][j-1]
            if(j+1<3):
                a[i][j+1]=1-a[i][j+1]
            if(i+1<3):
                a[i+1][j]=1-a[i+1][j]
            a[i][j]=1-a[i][j]
for i in range(3):
    print(*a[i],sep='')