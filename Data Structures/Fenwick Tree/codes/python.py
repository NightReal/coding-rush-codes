tree = [0] * MAXN


def add(i, x):
    while i < MAXN:
        tree[i] += x
        i += i & (-i)


def get(i):
    ans = 0
    while i > 0:
        ans += tree[i]
        i -= i & (-i)
    return ans
