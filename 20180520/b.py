# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Grand Contest 024 B問題 WA
Author     : Kitaura Hiromi
LastUpdate : 20180520
Since      : 20180520
"""
N = int(input())
p = [int(input()) for i in range(N)]
q = [0 for i in range(N)]
for i in range(N):
    q[p[i]-1] = i

cnt = 1
max_cnt = 1
for i in range(N-1):
    if q[i+1] > q[i]:
        cnt += 1
    else:
        max_cnt = max(max_cnt, cnt)
        cnt = 1
max_cnt = max(max_cnt, cnt)
print(N - max_cnt)