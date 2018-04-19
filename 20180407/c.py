A, B, C = map(int, input().split(" "))
cnt = 0

if (A%2 == B%2) and (B%2 == C%2):
    pass
else:
    if A%2 == B%2:
        A += 1
        B += 1
        cnt += 1
    elif A%2 == C%2:
        A += 1
        C += 1
        cnt += 1
    else:
        B += 1
        C += 1
        cnt += 1

ABC = sorted([A, B, C])
cnt += (ABC[2] - ABC[1]) // 2
cnt += (ABC[2] - ABC[0]) // 2
print(cnt)