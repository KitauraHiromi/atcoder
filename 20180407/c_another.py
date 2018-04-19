# -*- coding: utf-8 -*-
"""
Contents   : AtCoder 20180407 c問題用コード
Author     : Kitaura Hiromi
LastUpdate : 20180414
Since      : 20180414
https://img.atcoder.jp/arc094/editorial.pdf
"""

# 整数A B Cが入力される
A, B, C = map(int, input().split(" "))
sumABC = sum([A, B, C])
maxABC = max([A, B, C])

# 操作により合計値の遇奇は変化しない
# 操作によりそれぞれの値は減少しない
# そのため、合計値が少なくとも3つの値の最大値の3倍か、それ+1になったとき以降に3つの値は等しくなる
# 実は、合計値が少なくとも3つの値の最大値の3倍か、それ+1になったときは必ず存在し、その時が最小試行回数である
if maxABC%2 == sumABC%2:
    print((maxABC*3 - sumABC) // 2)
else:
    print((maxABC*3 + 3 - sumABC) // 2)