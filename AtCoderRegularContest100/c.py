N = int(input())
sum = 0
a = list(map(int, input().split()))
for i in range(N):
    a[i] -= (i + 1)
    sum += a[i] / N
mean = int(sum)
sad1 = 0
sad2 = 0
for i in range(N):
    sad1 += abs(a[i] - mean)
    sad2 += abs(a[i] - mean + 1)
print(min([sad1, sad2]))