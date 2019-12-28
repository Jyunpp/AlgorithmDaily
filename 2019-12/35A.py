with open('input.txt','r') as f:
    fs = f.read().strip().split('\n')

ans = fs[0]
for i in range(1,4):
    a, b = fs[i].split()
    if a == ans:
        ans = b
    elif b == ans:
        ans = a 

with open('output.txt','w') as f:
    f.write(ans)