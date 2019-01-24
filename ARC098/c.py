# -*- coding: utf-8 -*-
"""
Contents   : ARC098 C問題 AC
Author     : Kitaura Hiromi
LastUpdate : 20180526
Since      : 20180526
"""
N = int(input())
S = input()
cnt = 0
for s in S[1:]:
    if s == "E":
        cnt += 1
cnt_list = []
cnt_list.append(cnt)
for i in range(len(S)-1):
    if S[i] == "E" and S[i+1] == "E":
        cnt -= 1
        cnt_list.append(cnt)
    elif S[i] == "E" and S[i+1] == "W":
        cnt_list.append(cnt)
    elif S[i] == "W" and S[i+1] == "E":
        cnt_list.append(cnt)
    else:
        cnt += 1
        cnt_list.append(cnt)
print(min(cnt_list))