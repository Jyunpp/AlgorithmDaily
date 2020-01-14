# 20200114 19:15 ~ 19:19

for T in range(int(input())):
    arr = list(map(int, input().split()))
    arr = sorted(arr)
    if arr[0] + 2  >= arr[2]:
        print(0)
    else :
        print(2*(arr[2]-arr[0]-2))