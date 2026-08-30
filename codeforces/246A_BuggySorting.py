import sys


n=int(input())
if n==1 or n==2:
    print(-1)
    sys.exit()
for _ in range(n-1):
    print("5", end=" ")
print("3")