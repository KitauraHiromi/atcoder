# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Regular Contest 096 TLE O(N!)
             深さ優先探索
Author     : Kitaura Hiromi
LastUpdate : 20180422
Since      : 20180421
"""
    
N, C = map(int, input().split())
x = []
v = []
for i in range(N):
    x_i, v_i = map(int, input().split())
    x.append(x_i)
    v.append(v_i)

ret = 0
def dfs(x, v, x_rest, v_rest, num, pos, cal):
    global ret
    if num == N:
        return cal
    else:
        for i in range(N - num):
            dist = abs(x[i] - pos)
            new_cal = max(cal, cal + v[i] - min(dist, C - dist))
            ret = max(ret, dfs(x[:i] + x[i+1:], v[:i] + v[i+1:], x_rest + [x[i]], v_rest + [v[i]], num + 1, x[i], new_cal))
    return ret

print(dfs(x, v, [], [], 0, 0, 0))