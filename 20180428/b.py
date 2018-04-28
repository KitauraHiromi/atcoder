N = int(input())
S = []
for i in range(N):
    S.append(input())
def check(S, A, B):
    for i in range(N):
        for j in range(N):
            if i + A < N:
                a = i + A
            else:
                a = i + A - N
            if j + B < N:
                b = j + B
            else:
                b = j + B - N
            if j + A < N:
                c = j + A
            else:
                c = j + A - N
            if i + B < N:
                d = i + B
            else:
                d = i + B - N
            if S[a][b] != S[c][d]:
                return False
    return True

cnt = 0
for i in range(N):
    for j in range(N):
        if check(S, i, j):
            cnt += 1
print(cnt)