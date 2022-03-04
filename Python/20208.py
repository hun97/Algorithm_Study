n, m, h = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
mint_pos = []
start_x = 0
start_y = 0
cnt_mint = 0
max_mint = 0

for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            start_x = i
            start_y = j
        elif arr[i][j] == 2:
            mint_pos.append((i, j))
mint_pos.append((start_x, start_y))


def solve(x, y):
    global m, h, cnt_mint, max_mint
    for i in range(len(mint_pos)):
        mint_x, mint_y = mint_pos[i]
        cost = abs(x - mint_x) + abs(y - mint_y)
        if arr[mint_x][mint_y] == 2 and cost <= m:
            arr[mint_x][mint_y] = 0
            m -= cost
            m += h
            cnt_mint += 1
            solve(mint_x, mint_y)
            arr[mint_x][mint_y] = 2
            m += cost
            m -= h
            cnt_mint -= 1
        elif arr[mint_x][mint_y] == 1 and cost <= m:
            max_mint = max(cnt_mint, max_mint)


solve(start_x, start_y)
print(max_mint)
