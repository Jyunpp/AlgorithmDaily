# 20200122 19:05 ~ 19:30 ~ 19:40
 
for t in range(int(input())):
    n, d = map(int, input().split())
    if n>=d:
        print("YES")
    else:
        sqrt = int(pow(d, 0.5))
        need = sqrt-1 + int(d/sqrt) + int((d/sqrt) != int(d/sqrt))
        if need <=n:
            print("YES")
        else:
            print("NO")