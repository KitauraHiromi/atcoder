def dfs(S, T, Num):
    if Num == W:
        print(T)
    else:
        for i in range(W - Num):
            dfs(S[:i]+S[i+1:], T+[S[i]], Num+1)

a = [1,2,3,4,5,6,7]
W = len(a)
print(dfs(a, [], 0))