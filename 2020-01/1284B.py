# 20200104 21:11 ~ 21:50
import bisect

n = int(input())
minis = []
maxis = []
self_test_cnt = 0
for N in range(n):
    l = list(map(int, input().split()))
    sz = l[0]
    curr = l[1:]
    mini = 987654321
    maxi = -1
    self_test = 0
    for i in curr:
        if i > maxi:
            maxi = i
        if i > mini:
            self_test = 1
        if i < mini:
            mini = i
    self_test_cnt += self_test
    if self_test == 0:
        minis.append(mini)
        maxis.append(maxi)

ans = 2 * self_test_cnt * (n - self_test_cnt) + self_test_cnt*self_test_cnt
minis = sorted(minis)
maxis = sorted(maxis)
for i in maxis:
    ans += bisect.bisect_left(minis, i)
print(ans)