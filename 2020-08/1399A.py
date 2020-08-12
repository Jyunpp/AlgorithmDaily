# 20200812 20:51 ~ 20:54
for i in range(int(input())):
    n = int(input())
    arr = sorted(list(map(int, input().split())))
    ret = "YES"
    for i in range(1, n):
        if arr[i] - arr[i-1] >= 2:
            ret = "NO"
    print(ret)
