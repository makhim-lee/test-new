line_counter = 0
data_header = []
customer_list = []

with open("score.csv")as customer_data:

    while 1:
        data = customer_data.readline()
        if not data:break
        if line_counter == 0 :
            data_header = data.split(",")
            
        else : 
            customer_list.append(data.split(","))
        
        line_counter += 1
        
print("Header: ", data_header)
for i in range(10):
    print(f"Data , {i} : {customer_list[i]}")
print(len(customer_list))