"""
Satar Allah
Problem A 1200
Problem url : "https://codeforces.com/contest/1200/problem/A"
Approach : implementation 
"""

n = int(input())
stry = input()
 
reg = [0 for i in range(10)]
for ltr in stry:
    if ltr== 'L':
        for idx in range(10):
            if reg[idx] == 0:
                reg[idx] = 1
                break
    elif ltr =='R':
        for idx in range(1,11):
            if reg[-idx] == 0:
                reg[-idx] = 1
                break
    else:
        reg[int(ltr)] = 0
print(*reg, sep="")