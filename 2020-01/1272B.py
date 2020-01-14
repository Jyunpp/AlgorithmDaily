# 20200114 19:20 ~ 19:30

for T in range(int(input())):
    ans = 0
    ansStr = ""
    arr = input()
    mp = {
        'L' : 0,
        'R' : 0,
        'U' : 0,
        'D' : 0
    }
    for ch in arr:
        mp[ch]+=1
    lr = min(mp['L'], mp['R'])
    ud = min(mp['U'], mp['D'])
    if ud==0:
        if lr==0:
            print(0)
            print()
        else:
            print(2)
            print("LR")
    elif lr==0:
        if ud==0:
            print(0)
            print()
        else:
            print(2)
            print("UD")
    else :
        ans += (lr + ud)*2
        for i in range(lr):
            ansStr += "L"
        for i in range(ud):
            ansStr += "U"
        for i in range(lr):
            ansStr += "R"
        for i in range(ud):
            ansStr += "D"

        print(ans)
        print(ansStr)