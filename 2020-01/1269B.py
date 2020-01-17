# 20200117 23:30 ~ 23:42

n, m = map(int, input().split())

a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())))
l = len(b)
for i in range(l):
    b.append(m + b[i])

ans = -1
for i in range(n):
    isEnded = True
    diff = b[i] - a[0]
    for j in range(1, n):
        if diff != (b[i+j] - a[j]):
            isEnded = False
            break
    if isEnded == True:
        ans = abs(diff)
        break
print(ans)