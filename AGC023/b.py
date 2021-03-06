# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Grand Contest 023 AC
Author     : Kitaura Hiromi
LastUpdate : 20180502
Since      : 20180502
"""

N = int(input())
S = []
for i in range(N):
    S.append(input())

# for文は遅いので転置を使うと速くなる
def check(S, A, B):
    for i in range(N):
        for j in range(i+1, N):
            # if S[i][j+B-N] != S[j][i+B-N]:
            if S[i][j] != S[j][i]:
                return 0
    return 1

cnt = 0
for i in range(N):
    # cnt += check(S, 0, i)
    cnt += check(S[i:] + S[:i], 0, i)
print(cnt * N)