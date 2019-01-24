# -*- coding: utf-8 -*-
"""
Contents   : Atcoder Beginners Selection ABC049C AC
Author     : Kitaura Hiromi
LastUpdate : 20180525
Since      : 20180428
"""
S = input()

S = S[::-1]
T = ""
cnt = 0
while len(T) < len(S):
    if(S[cnt:cnt+3] == "mae"):
        T += "maerd"
        cnt += 5
    elif(S[cnt:cnt+3] == "rem"):
        T += "remaerd"
        cnt += 7
    elif(S[cnt:cnt+3] == "esa"):
        T += "esare"
        cnt += 5
    else:
        T += "resare"
        cnt += 6
if T == S:
    print("YES")
else:
    print("NO")