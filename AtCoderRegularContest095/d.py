# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Regular Contest 095 d問題 Accepted
Author     : Kitaura Hiromi
LastUpdate : 20180414
Since      : 20180414
"""

# c(m, n) = (m+n)!/m!n!
# mが同じな場合、nはmの半分なら最大
# mが大きいほどc(m, n)は大きい

n = int(input())
a = list(map(int, input().split(" ")))

max_a = max(a)
tmp = 0
for i in range(n):
    if abs(max_a / 2 - tmp) > abs(max_a / 2 - a[i]):
        tmp = a[i]
print(max_a, tmp)