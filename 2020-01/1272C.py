# 20200114 19:30 ~ 19:38

n, k = map(int, input().split())
arr = input()
only = list(map(str, input().split()))

ans = 0
curr = 0
for i in arr:
    if i in only:
        curr+=1
    else:
        ans += int((curr*(curr+1))/2)
        curr=0
ans += int((curr*(curr+1))/2)
print(ans)