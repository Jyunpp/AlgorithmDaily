# 20200106 01:48 ~ 01:50
for t in range(int(input())):
    arr = sorted(list(map(int, input().split())))
    print("Yes" if arr[0] + arr[1] + 1 >= arr[2] else "No")