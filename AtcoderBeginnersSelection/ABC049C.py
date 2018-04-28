# -*- coding: utf-8 -*-
"""
Contents   : Atcoder Beginners Selection ABC049C RE
Author     : Kitaura Hiromi
LastUpdate : 20180428
Since      : 20180428
"""
S = input()

def dfs(s, N):
    if len(s) > N:
        return False
    elif len(s) == N:
        if s == S:
            return True
    elif s == S[:len(s)]:
        return dfs(s + "dream", N) or dfs(s + "dreamer", N) or dfs(s + "erase", N) or dfs(s + "eraser", N)
    return False

if dfs("", len(S)):
    print("YES")
else:
    print("NO")