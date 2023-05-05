#width = int(input("width : "))
#height = int(input("height : "))

str = input("width height :")
list = str.split()
print(list)
width = int(list[0])
height = int(list[1])


area = width * height

print("area : ", area)