#report = input("국, 영, 수 :")
#list = report.split()
#sum = int(list[0]) + int(list[1]) + int(list[2])

# kor,eng,mat = list
# sum = int(kor) +int(eng) + int(mat)

list = list(map(int, input("국, 영, 수 :").split()))

print("총점 : ", sum(list), "평균 : ", sum(list)/len(list))
