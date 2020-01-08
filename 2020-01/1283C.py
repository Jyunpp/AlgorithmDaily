# # 20200108 20:00 ~ 20:10 studied solution
from random import shuffle as s

n = int(input())
arr = list(map(int, input().split()))
rands = [i+1 for i in range(n)]
needs = []
cnt = n
for i in range(n):
    if arr[i] != 0:
        rands.remove(arr[i])
        cnt-=1
    else:
        needs.append(i+1)

ing = True
while ing:
    ing = False
    s(rands)
    for i in range(cnt):
        arr[needs[i]-1] = rands[i]
        if needs[i] == rands[i]:
            ing = True
            break
print(' '.join(map(str, arr)))