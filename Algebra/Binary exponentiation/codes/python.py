def binaryPow(a, n):
    ans = 1
    while n:
        if n & 1:
            ans *= a
        n >>= 1
        a *= a
    return ans
