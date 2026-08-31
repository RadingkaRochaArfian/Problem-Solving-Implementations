s1,s2=input().split()
print(s1,s2)
n=int(input())
for _ in range(n):
    s3,s4=input().split()
    if s3==s1:
        s1=s4
    elif s3==s2:
        s2=s4
    print(s1,s2)