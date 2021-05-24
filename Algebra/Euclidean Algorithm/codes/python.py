def gcd(a, b):
    while a:
        b %= a
        a, b = b, a
    return b
