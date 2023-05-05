import random

def isPass(scores):
    return scores >= 60

#scores = [random.randint(45, 100) for _ in range(1, 10+1)]
#result = list(filter(isPass, scores))
#print(result)


print(list(filter(isPass, [random.randint(45, 100) for _ in range(1, 10+1)])))