list = [i for i in range(1, 11)]

i = 0
while i < len(list):
    if list[i] % 2 != 1:
        list.remove(list[i])
        del list[i]
        list.pop(i)
    i += 1

print(list)