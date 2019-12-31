# 20191231 19:04 ~ 19:09
t = int(input())
for T in range(t):
    n, k1, k2 = map(int, input().split())
    ans = "NO"
    if n in list(map(int, input().split())):
        ans = "YES"
    input()
    print(ans)