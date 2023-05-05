import random

randNums = random.sample([1, 2, 3, 4, 5, 6, 7, 8, 9], 3)
#randNums.append(int(random.random() * 9) + 1) // append ==push_beck
while(True) : 
    myNums = list(map(int, input("Enter 3 nums : ").split()))
    strike = ball = 0 
    for i in range(0,3):
        for j in range(0,3):
            if (randNums[i] == myNums[j]) and (i == j):
                strike += 1
            elif (randNums[i] == myNums[j]) and (i != j):
                ball += 1
    if(strike == 3):
        print(f"your win! nums is {randNums}")
        break
    else :
        print(f"ball : {ball} strike : {strike}")
        

