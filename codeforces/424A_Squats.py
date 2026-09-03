import sys


n=int(input())
s=input()
cap=0
low=0
for i in range(n):
    if s[i]=='X':
        cap+=1
    else:
        low+=1
if cap==low:
    print(0)
    print(s)
    sys.exit()
l=list(s)
cnt=0
for i in range(n):
    if cap==low:
        break
    if cap>low and l[i]=='X':
        l[i]='x'
        cap-=1
        low+=1
        cnt+=1
    elif low>cap and l[i]=='x':
        l[i]='X'
        low-=1
        cap+=1
        cnt+=1
print(cnt)
print(''.join(l))