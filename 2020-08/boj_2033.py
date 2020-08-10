# 20200811 00:16 ~ 
def roundUp(n, digit):
    q = n/digit
    lastQ = int(q%10)
    if lastQ >=5:
        return (int(n/digit/10) + 1)*digit*10
    else:
        return int(n/digit/10)*digit*10

n = int(input())
digit = 1

while(True):
    if n >= digit*10:
        n = roundUp(n, digit)
        digit *= 10
    else:
        break

print(n)