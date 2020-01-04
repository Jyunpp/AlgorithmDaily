# 20200104 21:05 ~ 21:11

n, m = map(int, input().split())
s = list(map(str, input().split()))
t = list(map(str, input().split()))
T = int(input())
for i in range(T):
    a = int(input())
    a-=1
    print(s[a%n] + t[a%m])