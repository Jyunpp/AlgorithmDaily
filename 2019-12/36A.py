with open('input.txt','r') as f:
    fs = f.read().strip().split('\n')

ans = "YES"
n = fs[0]
s = fs[1].strip('0').split('1')
s = s[1:-1]
for i in s:
    for j in s:
        if i!=j: ans = "NO"

with open('output.txt','w') as f:
    f.write(ans)