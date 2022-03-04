def dfs(depth, idx):
    if depth == l:
        cnt_v = 0
        cnt_c = 0
        for i in range(l):
            if arr[i] in vowel:
                cnt_v += 1
            else:
                cnt_c += 1
        if cnt_v >= 1 and cnt_c >= 2:
            print("".join(arr))
            return
    for i in range(idx, c):
        arr.append(s[i])
        dfs(depth + 1, i + 1)
        arr.pop()


l, c = map(int, input().split())
s = input().split()
s.sort()
vowel = ['a', 'e', 'i', 'o', 'u']
check = [False] * c
arr = []
dfs(0, 0)
