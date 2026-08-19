import sys


t,s,x=map(int,input().split())
if x<t:
    print("NO") 
    sys.exit()

left=x-t
if left%s==0 or ((left-1)%s==0 and (left-1)!=0):
    print("YES")
else:
    print("NO")
