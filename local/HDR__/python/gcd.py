def gcd(a, b):
    remain = a % b
    while remain != 0:
        a = b
        b = remain
        remain = a%b
    return b

a, b = map(int, input("input a b : ").split())
print(gcd(a, b))


