# 20200118 19:26 ~ 19:47 ~ 20:20

n = int(input())
arr = list(map(int, input().split()))

ans_1 = 0
ans_2 = 0

for i in range(n):
    if i%2 == 1:
        ans_1+=int(arr[i]/2) + arr[i]%2
        ans_2+=int(arr[i]/2)
    else:
        ans_1+=int(arr[i]/2)
        ans_2+=int(arr[i]/2) + arr[i]%2

print(min(ans_1, ans_2))