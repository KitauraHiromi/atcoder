# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Grand Contest 024 B問題 WA
Author     : Kitaura Hiromi
LastUpdate : 20180520
Since      : 20180520
"""
N = int(input())
seq = []
cnt_front = 1
cnt_back = N
for i in range(N):
    p = int(input())
    if cnt_front == p:
        cnt_front += 1
    seq.append(p)

for i in range(N):
    if cnt_back == seq[- i - 1]:
        cnt_back -= 1

cnt_back = N - cnt_back
if cnt_back < cnt_front:
    print(N - cnt_back)
else:
    print(N - cnt_front)