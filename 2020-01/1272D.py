# 20200114 19:38 ~ 20:05

n = int(input())
arr = list(map(int, input().split()))

incLen = list()
incS = list()

tempAns = 1

last = arr[0]
currS = 0
currLen = 1
for i in range(1, n):
    curr = arr[i]
    if curr > last:
        last = curr
        currLen += 1
    else:
        tempAns = max(tempAns, currLen)
        incLen.append(currLen)
        incS.append(currS)
        last = arr[i]
        currS = i
        currLen = 1
tempAns = max(tempAns, currLen)
incLen.append(currLen)
incS.append(currS)

for i in range(0, len(incLen)-1):
    prevLast = arr[incS[i] + incLen[i] - 1]
    nextFirst = arr[incS[i+1]]
    if incS[i] + incLen[i] - 2 >= 0 and incLen[i] >=2:
        prevLLast = arr[incS[i] + incLen[i] - 2]
        if nextFirst > prevLLast:
            tempAns = max(tempAns, incLen[i] - 1 + incLen[i+1])
    if incLen[i+1] >=2:
        nextFFirst = arr[incS[i+1]+1]
        if nextFFirst > prevLast:
            tempAns = max(tempAns, incLen[i] + incLen[i+1] - 1)

print(tempAns)