t=int(input())
mod=1e9+7
for _ in range(t):
    l,r=map(int,input().split(' '))
    ans=0
    for i in range(l,r+1):#13=1101 inkaran= 0010 15-13=2 2=1<<1 12=1100 inkaran=0011 
        ln=i.bit_length()
        temp=0
        for j in range(ln):
            b=1<<j
            if i & b==b:
                temp+=j
        ans+=temp
    print(ans) 