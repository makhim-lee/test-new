def make_list(n = 10):
    return [i for i in range(1, n+ 1)]

nums = make_list()
print(nums)
nums = make_list(5)
print(nums)