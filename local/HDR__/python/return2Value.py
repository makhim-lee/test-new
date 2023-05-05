def f():
    return 100, 200  # --> packing --> tuple
    
print(f())

a, b = f()

print(a, b)