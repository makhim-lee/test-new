import random

#balls = []
#for i in range(1, 45 + 1):
#    balls.append(i)
balls = [i for i in range(1, 45 + 1)]  #list comprehension

random.shuffle(balls)
randNums = balls[0:3]

myNums = list(map(int, input("Enter 3 nums (1~45) : ").split()))
strike = 0
ball = 0
for i in range(0,3):
    for j in range(0,3):
        if (randNums[i] == myNums[j]) and (i == j):
            strike += 1
        elif (randNums[i] == myNums[j]) and (i != j):
            ball += 1
            

rank =7 - (2 * strike + ball)

print(f"your {rank}st! lotto is {randNums}")


