n = int(input())
first = n // 10
second = n % 10
cnt = 1
res = second * 10 + (first + second) % 10
while n != res:
    first = res // 10
    second = res % 10
    cnt += 1
    res = second * 10 + (first + second) % 10

print(cnt)
