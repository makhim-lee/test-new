a, b = map(int, input("input : ").split())

try:
    result = a/b
    
    if b == 0:
        raise ZeroDivisionError()
    print(f"{a} / {b} = {result}")
except ZeroDivisionError as e:
    print(e)
    print("you can't divide by zero!")