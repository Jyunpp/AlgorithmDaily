# 20200101 03:00 ~ 03:52
d = dict()
n, k = map(int, input().split())
for i in range(k+1):
    arr = [j+1 for j in range(k+1)]
    arr.remove(i+1)
    print('?', ' '.join(map(str,arr)))
    
    pos, a = map(int, input().split())
    d[a] = d.get(a, 0) + 1

keys = sorted(d.keys())
print('!', d[keys[1]])