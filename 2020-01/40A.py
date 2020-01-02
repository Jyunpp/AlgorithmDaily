# # 20200103 00:54 ~ 01:01
x, y = map(int, input().split())
dist = pow(x**2 + y**2, 0.5)
if dist%1 == 0:
    print("black")
else:
    dist = int(dist)
    is_odd = (dist%2 == 1)
    if is_odd != (x*y>0):
        print("black")
    else:
        print("white")