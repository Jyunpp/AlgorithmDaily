# 20191231 19:36 ~ 19:50
t = int(input())
for T in range(t):
    n = int(input())
    xor = 0
    s = 0
    for i in list(map(int, input().split())):
        xor ^= i
        s += i
    print(2)
    print(xor, s+xor)