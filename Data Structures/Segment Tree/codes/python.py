arr = [0] * 4 * MAXN
tree = [0] * 4 * MAXN


def build(v, l, r):
    if l + 1 == r:
        tree[v] = arr[l]
        return
    m = (l + r) // 2
    build(2 * v + 1, l, m)
    build(2 * v + 2, m, r)
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2]


def update(v, l, r, i, x):
    if i < l or i >= r:
        return
    if l + 1 == r:
        arr[i] = x
        tree[v] = x
        return
    m = (l + r) // 2
    update(2 * v + 1, l, m, i, x)
    update(2 * v + 2, m, r, i, x)


def get(v, l, r, ql, qr):
    if ql >= r or l >= qr:
        return 0
    if ql <= l and r <= qr:
        return tree[v]
    m = (l + r) // 2
    a = get(2 * v + 1, l, m, ql, qr)
    b = get(2 * v + 2, m, r, ql, qr)
    return a + b
