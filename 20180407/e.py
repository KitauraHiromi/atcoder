# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Regular Contest094 e問題 未完成
Author     : Kitaura Hiromi
LastUpdate : 20180414
Since      : 20180414
"""

# 最終的に, 1組以外はすべて0になる

N = int(input())
queA = []
queB = []
for i in range(N):
    A, B = map(int, input().split(" "))
    queA.append(A)
    queB.append(B)

cnt = 0
if np.allclose(queA, queB):
    print(cnt)
    return 0

# queA[i] <= queB[i]なるqueA[i]を0にする.
# queA[i] = 0か, queA[i] > queB[i]のみになる.
for i in range(N):
    if queA[i] <= queB[i]:
        cnt += queA[i]
        queB[i] -= queA[i]
        queA[i] = 0

if np.allclose(queA, queB):
    print(cnt)
    return 0
print(sum(queA), sum(queB))
# Aの行動は, queA[i] > queB[i]なるqueA[i]を-1するのみになる.
# BはqueA[i] = 0なるqueB[i]を-1にして0にする行動をとる.
# この行動がすべて終われば,終了.
for i in range(N):
    if queA[i] == 0:
        cnt += queB[i]
        queB[i] = 0
    print(sum(queA), sum(queB))
