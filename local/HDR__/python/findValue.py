list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

value = int(input("value : "))

for i in list:
    if value == i:
        break

if value in list :
    print("found")
    print(i)
elif value not in list:
    print("notfound")