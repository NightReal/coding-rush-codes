def prefixFunction(s):
    n = len(s)
    pref = [0 for i in range(n)]
    k = 0
    for i in range(1, n):
        while k > 0 and s[i] != s[k]:
            k = pref[k - 1]
        if s[i] == s[k]:
            k += 1
        pref[i] = k
    return pref
