num = int(input("num : "))

if num%2 == 1:
    print("num is odd number")
else :
    print("nums is even number")
    
result = [num**2 for num in range(1,10+1) if num % 2 == 1]

print(result)    




    