for i in range(1, 6):
    line = ""
    for j in range(1,6-i):
        line += " "
    for j in range(1,2*i): #6-i,5+i
        line += "*"
    print(line)
    

for i in range(1, 6):
    line = ""
    for j in range(1, 6):
        if i == j or i + j == 6 :
            line += "*"
        else :
            line += " "
    print(line)


    