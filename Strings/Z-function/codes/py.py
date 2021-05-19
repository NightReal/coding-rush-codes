def zFunction(s):
    n = len(s)
    l = r = 0
    z = [0 for i in range(n)]
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + l, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            r = i + z[i] - 1
            l = i
    return z
