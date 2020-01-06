# 20200106 22:01 ~ 22:20
for t in range(int(input())):
    n, s = map(int, input().split())
    maxi = -1
    ans = 0
    ps = 0
    for i, j in zip(range(1, n+1), list(map(int, input().split()))):
        ps += j
        if maxi < j:
            if ps-j <= s:
                maxi = j
                ans = i
            else:
                break
        elif ps - maxi > s:
            break
    if ps <=s:
        ans = 0
    print(ans)