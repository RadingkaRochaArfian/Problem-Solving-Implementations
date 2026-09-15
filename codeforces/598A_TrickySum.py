t=int(input())
for _ in range(t):
    n=int(input())
    total=n*(n+1)//2
    pos=n.bit_length()-1
    msb=1<<(pos)
    sub=(msb*3)+(msb-2)
    ans=total-sub
    print(ans)