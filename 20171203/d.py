import numpy as np

N, C = map(int, input().split(' '))
s = []
t = []
c = []
for i in range(N):
    s_i, t_i, c_i = map(int, input().split(' '))
    s.append(s_i)
    t.append(t_i)
    c.append(c_i - 1)
T = 2*max(t)
table = np.zeros(T)
for i in range(C):
    table_i = np.zeros(T)
    for j in range(N):
        if c[j] == i:
            table_i[2*s[j]-1: 2*t[j]] = 1
    table += table_i
print(int(np.max(table)))