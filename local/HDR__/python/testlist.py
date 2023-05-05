>>> nums = [1, 2, 3]
>>> nums.append(4)
>>> print(nums)
[1, 2, 3, 4]
>>> nums.insert(0, 0)
>>> print(nums)
[0, 1, 2, 3, 4]
>>> num2 = [5, 6, 7]
>>> nums.extend(num2)
>>> print(nums)
[0, 1, 2, 3, 4, 5, 6, 7]

>>> del nums[0]
>>> print(nums)
[1, 2, 3, 4, 5, 6, 7]
>>> exit()