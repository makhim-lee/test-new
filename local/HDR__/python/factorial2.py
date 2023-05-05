def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n - 1)
    

result = [factorial(n) for n in range(1, 100+1)]
result = list(map(factorial, [n for n in range(1, 100+1)]))
print(result)