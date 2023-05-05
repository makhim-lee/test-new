
matrix = []

nums = [1, 2, 3, 4]
nums2 = [5, 6]
nums3 = [10, 11, 12]

matrix = [nums, nums2, nums3]
print(matrix)


#total = matrix[i][j] for i in range(0, len(matrix)) for j in range(0,len(matrix[i]))

total = sum(matrix[i][j] for i in range(len(matrix)) for j in range(len(matrix[i])))
print(total)
total1 = 0
total1 += sum(matrix[i] for i in range(len(matrix)))
print(total1)


