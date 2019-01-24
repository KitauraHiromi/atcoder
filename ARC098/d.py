# -*- coding: utf-8 -*-
"""
Contents   : ARC D問題 AC
Author     : Kitaura Hiromi
LastUpdate : 20180527
Since      : 20180526
"""
from operator import xor
from functools import reduce

N = int(input())
A = list(map(int, input().split()))

cnt = 0
r = 0
tmp = 0
for l in range(N):
    while r < N and tmp & A[r] == 0:
        # 区間の右端の要素を足す
        tmp ^= A[r]
        r += 1
    # print(l, r)
    cnt += (r - l)
    # 区間の左端の要素を引く
    tmp ^= A[l]
print(cnt)