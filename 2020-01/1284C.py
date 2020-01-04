# 20200105

n, m = map(int, input().split())
facts = list()
fact = 1
for i in range(1, n+1):
    fact *= i
    fact %= m
    facts.append(fact)

ans = 0
for i in range(1, n+1):
    ans += facts[i-1] * facts[n-i] * (n-i+1)
    ans %= m

print(ans)