# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Grand Contest 023
Author     : Kitaura Hiromi
LastUpdate : 20180502
Since      : 20180428
"""
N = int(input())
A = list(map(int, input().split(" ")))

# O(NlogN)
S = []
tmp = 0
for i in range(N):
    S.append(tmp)
    tmp += A[i]
S.append(tmp)
S = sorted(S)
cnt = 1
ret = 0
tmp = S[0]
for i in range(1, len(S)):
    if tmp == S[i]:
        cnt += 1
    else:
        ret += cnt * (cnt - 1) // 2
        cnt = 1
        tmp = S[i]
ret += cnt * (cnt - 1) // 2
print(ret)