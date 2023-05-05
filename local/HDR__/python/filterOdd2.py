def isOdd(num):
    return num % 2 == 1

print(f"list :{list(filter(isOdd, range(1, 11)))}")


nums = [i for i in range(1, 11)]
#result = list(filter(isOdd, range(1, 11)))

result = list(filter(lambda num:num%2 == 1, nums))




