"""
Satar Allah
Problem C 1006
Problem url : "https://codeforces.com/contest/1006/problem/C"
Approach two pointer solution 
"""

n = int(input())
arr = list(map(int,input().split()))
 
lft = 0
rgt = n - 1
 
ans = []
smlft = 0
smrgt = 0
reg = {}
while lft<rgt:
    if lft not in reg.keys():
        smlft += arr[lft]
        reg[lft] = 0
    if rgt not in reg.keys():
        smrgt += arr[rgt]
        reg[rgt] = 0
    if smlft > smrgt:
        rgt -= 1
    elif smlft < smrgt:
        lft +=1
    elif smlft == smrgt:
        ans.append(smlft)
        lft +=1
if len(ans) == 0:
    ans.append(0)
print(max(ans))