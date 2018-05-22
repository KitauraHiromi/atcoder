# -*- coding: utf-8 -*- 
"""
Contents   : AtCoder Grand Contest 024 A問題 AC
Author     : Kitaura Hiromi
LastUpdate : 20180520
Since      : 20180520
"""

A, B, C, K = map(int, input().split())
if K % 2 == 0:
    print(A - B)
else:
    print(B - A)