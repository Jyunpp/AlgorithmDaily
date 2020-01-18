# 20200118 19:10 ~ 19:22

n, k = map(int, input().split())
a = input()
aSub = a[:k]
ans = ""
for i in range(n):
    ans += aSub[i%k]
if int(ans) < int(a):
    aSub = str(int(aSub)+1)
    ans = ""
    for i in range(n):
        ans +=  aSub[i%k]
print(n)
print(ans)
