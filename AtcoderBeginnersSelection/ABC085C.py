# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Beginners Selection 085C AC
Author     : Kitaura Hiromi
LastUpdate : 20180426
Since      : 20180426
O(logN)の二分探索を最大N回繰り返す．計算量O(NlogN)
"""

N, Y = map(int, input().split())

def binary_search(li, val, lower=0, upper=None):
    '''
    required: li is sorted list.
    return index of val
    '''
    if lower < 0:
        return ValueError("lower must be non-negative")
    if upper is None:
        upper = len(li)
    while lower < upper:
        mid = (lower + upper) // 2
        if val == li[mid]:
            return mid
        if val >= li[mid]:
            upper = mid
        else:
            lower = mid + 1
    return None

flag = True
for i in range(N + 1):
    tmp = binary_search([1000 * i + 5000 * j + 10000 * (N - i - j) for j in range(N - i + 1)], Y)
    if tmp is not None and flag:
        print("{0} {1} {2}".format(N - i - tmp, tmp, i))
        flag = False
if flag:
    print("-1 -1 -1")