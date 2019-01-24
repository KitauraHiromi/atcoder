# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Regular Contest 096 c問題 AC
Author     : Kitaura Hiromi
LastUpdate : 20180421
Since      : 20180421
"""
A, B, C, X, Y = map(int, input().split(" "))
if A + B < 2 * C:
    print(X * A + Y * B)
else:
    if A < 2 * C and X > Y:
        print(Y * 2 * C + (X - Y) * A)
    elif B < 2 * C and X < Y:
        print(X * 2 * C + (Y - X) * B)
    else:
        print(max(X, Y) * 2 * C)