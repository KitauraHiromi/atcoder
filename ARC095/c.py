# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Regular Contest 095 c問題 Accepted
Author     : Kitaura Hiromi
LastUpdate : 20180414
Since      : 20180414
"""
import random
import copy

N = int(input())
X = list(map(int, input().split(" ")))
sorted_X = sorted(X)
med1 = sorted_X[N//2-1]
med2 = sorted_X[N//2]
for i in range(N):
    if X[i] <= med1:
        print(med2)
    else:
        print(med1)