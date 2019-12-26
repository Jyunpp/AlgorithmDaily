n, m = input().split()
n = int(n)
m = int(m)

arr = list(map(int, input().split()))
arr.sort()

ans = 0
for i in range(m):
    if arr[i] < 0:
        ans += arr[i]
print(ans*-1)