# 20191231 19:10 ~ 19:19 ~ 19:35
t = int(input())
for T in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    for i in range(n-1):
        if abs(arr[i]-arr[i+1]) >=2:
            print("YES")
            print(i+1, i+2)
            break
    else:
        print("NO")