# 20200117 23:30 ~ 23:42
# 20200118 00:45 ~ 00:50

n, m = map(int, input().split())

a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())))
l = len(b)
for i in range(l):
    b.append(m + b[i])

ans = 987654321
for i in range(n):
    isEnded = True
    diff = b[i] - a[0]
    for j in range(1, n):
        if diff != (b[i+j] - a[j]):
            isEnded = False
            break
    if isEnded == True:
        currAns = diff
        if currAns < 0:
            currAns += m
        ans = min(ans, currAns)
print(ans)