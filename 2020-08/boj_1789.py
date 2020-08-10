# 20200811 01:03 ~ 
n = int(input())
ans = 1
while(True):
    if n >= int(ans*(ans+1) / 2):
        ans+=1
    else:
        ans-=1
        break
print(ans)