def my_sum(*args):
    total = 0
    print("args : ",args)
    for value in args:
        total += value
    return total

def my_sum(*args):              #redefine!
    return sum(list(args))    


result = my_sum(1, 2, 3, 4, 5)
print("result : ", result)