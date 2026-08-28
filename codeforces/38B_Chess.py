s1=(input())
s2=(input())
arr=[[1]*8 for _ in range(8)]
row1=ord(s1[0])-ord('a')
col1=int(s1[1])-1
for i in range(8):
    for j in range(8):
        if i==row1 or j==col1:
            arr[i][j]=0
row2=ord(s2[0])-ord('a')
col2=int(s2[1])-1
forbid1={(row2-2,col2-1),(row2-2,col2+1),(row2-1,col2-2),(row2+1,col2-2),(row2+2,col2-1),(row2+2,col2+1),(row2+1,col2+2),(row2-1,col2+2)}
forbid2={(row1-2,col1-1),(row1-2,col1+1),(row1-1,col1-2),(row1+1,col1-2),(row1+2,col1-1),(row1+2,col1+1),(row1+1,col1+2),(row1-1,col1+2)}
for i in range(8):
    for j in range(8):
        if (i,j) in forbid1:
            arr[i][j]=0
        if (i,j) in forbid2:
            arr[i][j]=0
arr[row2][col2]=0
arr[row1][col1]=0
count=0
for i in range(8):
    for j in range(8):
        if arr[i][j]==1:
            count+=1
print(count)
