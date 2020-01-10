# 20200110 22:22 ~ 22:25
for T in range(int(input())):
    input()
    ans = 0
    isFirst = True
    for i in list(input().split("A")):
        if isFirst:
            isFirst = False
            continue
        ans = max(ans, len(i))
    print(ans)