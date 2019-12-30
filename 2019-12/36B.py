# 20191230 21:40 ~ 22:38

with open('input.txt','r') as f:
    fs = f.read().strip().split('\n')

n, k = fs[0].split()
n = int(n)
k = int(k)

arr = []
for i in range(1, n+1):
    row = []
    for j in fs[i]:
        row.append(j)
    arr.append(row)

ans = [['.' for i in range(n**k)] for j in range(n**k)]

def recur(n, k, r, c, len, color):
    # print('recur(', str(n), str(k), str(r), str(c), str(len), color, ')')
    global arr
    global ans
    for i in range(len):
        for j in range(len):
            ans[r+i][c+j] = color
    if len == 1:
        return
    if color == '.':
        for row, rd in zip(arr, (rdi for rdi in range(0, len, int(len/n))) ):
            for elem, cd in zip(row, (cdi for cdi in range(0, len, int(len/n))) ):
                recur(n, k, r+rd, c+cd, int(len/n), elem)

for row, rd in zip(arr, (rdi for rdi in range(0, n**k, n**(k-1))) ):
    # print(rd)
    for elem, cd in zip(row, (cdi for cdi in range(0, n**k, n**(k-1))) ):
        # print(cd)
        recur(n, k, rd, cd, n**(k-1), elem)


with open('output.txt','w') as f:
    for row in ans:
        for i in row:
            f.write(i)
        f.write('\n')