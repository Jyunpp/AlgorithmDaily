# # 20200107 19:30 ~ 19:32
for T in range(int(input())):
    h, m = map(int, input().split())
    print(60-m + (23-h)*60)