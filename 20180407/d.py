# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Regular Contest094 d問題 不正解
             全探索しようとしたが、s = A*Bが大きくなりすぎて無理くさい
             最大値だけ探せばいいから、数学的に簡単化する方法を考えたい
Author     : Kitaura Hiromi
LastUpdate : 20180414
Since      : 20180414
"""
from math import ceil

# 高橋くんのスコアsとし、スコアがそれ未満になる順位を(x, y)とすると、yは
# y < s / x
# を満たす.
# y = ceil(s / x) - 1なるyを順に選べば、スコアがそれ以下になる人数の最大数が求まる.

Q = int(input())
for i in range(Q):
    A, B = map(int, input().split(" "))
    cnt = 0
    s = A*B

    for j in range(1, s):
        if j != A:
            y = ceil(s // j) - 1
            if y > 0:
                for k in range(s, 1, -1):
                    if k > y:
                        pass
                    else:
                        cnt += 1
                        break
    print(cnt)
