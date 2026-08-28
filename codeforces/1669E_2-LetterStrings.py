from collections import defaultdict


t=int(input())
for _ in range(t):
    n=int(input())
    c1=defaultdict(int)
    c2=defaultdict(int)
    mp=defaultdict(int)
    ans=0
    for _ in range(n):
        s=input()
        a=s[0]
        b=s[1]
        ans+=c1[a] -mp[s]
        c1[a]+=1
        ans+=c2[b] -mp[s]
        c2[b]+=1
        mp[s]+=1
    print(ans)