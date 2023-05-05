year = int(input("year : "))

if year % 4 == 0 and year % 100 != 0 or year or year % 400 == 0 :
    print (f"{year} is leap") 
else:
    print (f"{year} is not leap") 