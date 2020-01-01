# 20200101 21:00 ~ 
n = int(input())
ps = []
for i in range(n):
    ps.append(list(map(int, input().split())))

if n==2:
    print(1)
    print(1)
else:
    ee = []
    eo = []
    oe = []
    oo = []
    while True:
        for i, p in zip(range(n), ps):
            if p[0]%2 == 0 and p[1]%2 == 0:
                ee.append(i+1)
            elif p[0]%2 == 1 and p[1]%2 == 0:
                oe.append(i+1)
            elif p[0]%2 == 0 and p[1]%2 == 1:
                eo.append(i+1)
            else:
                oo.append(i+1)
            if p[0]%2 == 1:
                p[0]-=1
            if p[1]%2 == 1:
                p[1]-=1
            p[0] = p[0]/2
            p[1] = p[1]/2
        a = None
        b = None
        for i in ee, eo, oe, oo:
            for j in ee, eo, oe, oo:
                if i==j:
                    continue
                if i and j and len(i)+len(j) == n:
                    a = i
                    b = j
        if a!=None:
            print(len(a))
            print(' '.join(map(str, a)))
            break
        if (eo or oe) and (oo or ee):
            eo.extend(oe)
            a = eo
        if a!=None:
            print(len(a))
            print(' '.join(map(str, a)))
            break
        ee.clear()
        eo.clear()
        oe.clear()
        oo.clear()