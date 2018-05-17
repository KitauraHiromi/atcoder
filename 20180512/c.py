# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Regular Contest C問題 TLE 200points
Author     : KitauraHiromi
LastUpdate : 20180517
Since      : 20180517
"""

def duplicate(substr, strs):
    for str in strs:
        if str[:len(substr)] == substr:
            return True
    return False

def head_char(substrs, k):
    dict = {}
    for i in range(len(substrs)):
        dict[substrs[i][0]] = 0
    for i in range(len(substrs)):
        if not duplicate(substrs[i], substrs[:i]):
            dict[substrs[i][0]] += len(substrs[i])
    sum = 0
    pre_sum = 0
    pre_alph = ""
    for alph in sorted(dict.keys()):
        if sum > k:
            return (pre_alph, pre_sum)
        pre_sum = sum
        pre_alph = alph
        sum += dict[alph]
    return (pre_alph, pre_sum)

def find_substring(substrs, K, ret):
    # print("K", K, "ret", ret)
    if K <= 0:
        return ret
    head, k = head_char(substrs, K-1)
    # print("head:", head)
    idxes = [pos for pos, substr in enumerate(substrs) if substr[0] == head]
    new_substrs = [substrs[idx][1:] for idx in idxes if substrs[idx][1:] != ""]
    # print("new_substrs", new_substrs)
    # print(new_substrs, K-k)
    return find_substring(new_substrs, K-k-1, ret+head)

s = input()
K = int(input())
substrs = [s[i:] for i in range(len(s))]
print(find_substring(substrs, K, ""))
