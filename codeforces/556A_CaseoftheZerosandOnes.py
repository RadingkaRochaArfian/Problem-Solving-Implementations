n=int(input())
s=input()
cnt1=0
cnt0=0
for x in s:
    if x=='1':
        cnt1+=1
    else:
        cnt0+=1
print(abs(cnt0-cnt1))