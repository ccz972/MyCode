x, y, s = input().split()
x = int(x)
y = int(y)

sum = 0

# s = str(s)
for c in s: 
    p = -1
    if c <= '9' and c >= '0':
        p = ord(c) - ord('0')
        # p = (int)((int)c - '0')
    elif c >= 'A' and c <= 'Z':
        # p = (int)((int)c - 'A' + 10)
        p = ord(c) - ord('A') + 10
    else :
        # p = (int)(c - 'a' + 36)
        p = ord(c) - ord('a') + 36

    sum = sum * x + p

# 
if (sum == 0) :
    print(0)
else :
    ans = []
    while sum :
        p = sum % y
        if p <= 9:
            ans.append(p)
        elif p <= 35:
            ans.append(chr(ord('A') + p - 10))
        else :
            ans.append(chr(ord('a') + p - 36))
        sum = sum // y

    n = len(ans)

    for i in range(n - 1, -1, -1) :
        print(ans[i], end='')
        # print(i)

# print(61 * 62 + 61)

# for i in range(120) :
#     print('z', end='')