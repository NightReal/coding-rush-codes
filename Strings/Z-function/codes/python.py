def zFunction(s):
    n = len(s)
    l = r = 0
    z = [0] * n
    for i in range(1, n):
        if i < r:
            z[i] = min(r - i, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] > r:
            r = i + z[i]
            l = i
    return z
