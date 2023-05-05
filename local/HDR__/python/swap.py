def swap(a, b):
    tem = a
    a = b
    b = tem
    return a, b
    
    
def swap2():
    global a, b
    tem = a
    a = b
    b = tem


a = 100
b = 200
print("a : ", a,"b : ", b)
a, b = swap(a,b)
print("a : ", a,"b : ", b)
swap2()
print("a : ", a,"b : ", b)