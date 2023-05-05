def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

# result = []
# for i in range(1, 100 + 1):
#   result.append(factorial(i)) 

#result = [factorial(i) for i in range(1, 100)]

result = list(map(factorial, range(1,100 + 1))  )
print(result)