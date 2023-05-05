nums = input("Enter 3 nums :")

list = nums.split()
# list = list(map(int, list))
for i in range(0,3):
    list[i] = int(list[i])

for i in range(0,3) :
    for k in range(i,3):
        if list[k] > list[i]:
            tem = list[k]
            list[k] = list[i]
            list[i] = tem
            
print(f"Max : {list[0]}, mid : {list[1]}, min : {list[2]}")