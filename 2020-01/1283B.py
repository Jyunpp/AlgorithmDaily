# # 20200107 19:32 ~ 19:37
for T in range(int(input())):
    n, k = map(int, input().split())
    print(int(int(n/k)*k + min(n%k,k/2)))