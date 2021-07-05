n, k = tuple(map(int, input().split()))

min_sum, max_sum = 0, 0
for _ in range(k):
    tmp = int(input())
    min_sum += tmp
    max_sum += tmp

for _ in range(n - k):
    min_sum += -3
    max_sum += 3

print(round(min_sum / n, 20), round(max_sum / n, 20))

