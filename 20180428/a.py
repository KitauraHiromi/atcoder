# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Grand Contest 023
Author     : Kitaura Hiromi
LastUpdate : 20180428
Since      : 20180428
"""
N = int(input())
A = list(map(int, input().split(" ")))


# O(N^2)
cnt = 0
for i in range(N):
    for j in range(i+1, N+1):
        if sum(A[i:j]) == 0:
            cnt += 1
print(cnt)