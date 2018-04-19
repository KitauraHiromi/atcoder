# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Regular Contest 95 TLE
Author     : Kitaura Hiromi
LastUpdate : 20180418
Since      : 20180416
"""

import numpy as np

def check_symmetric_by_cols_rearange(cols):
    center_flag = False
    while len(cols) != 0:
        col = cols.pop()
        upsidedown_col = col[::-1]
        if upsidedown_col in cols:
            cols.pop(cols.index(upsidedown_col))
        else:
            if W%2 == 0:
                return False
            elif col == upsidedown_col and center_flag is False:
                center_flag = True
                continue
            else:
                return False
    return True


def dfs(S, T, Num):
    ans = False
    if Num == H:
        return check_symmetric_by_cols_rearange(list(zip(*rows[T])))
    else:
        for i in range(H - Num):
            ans = ans or dfs(S[:i]+S[i+1:], T+[S[i]], Num+1)
    return ans

H, W = map(int, input().split(" "))
rows = []
for h in range(H):
    rows.append(input())
rows = np.array(rows)

if dfs(list(range(H)), [], 0):
    print("YES")
else:
    print("NO")