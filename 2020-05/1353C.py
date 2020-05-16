# 20200517 03:15 ~ 03:25

for T in range(int(input())):
    n = int(input())
    
    ans = 0
    for i in range(1, int(n/2)+1):
        ans += 4 * (2*i) * i
    
    print(ans)