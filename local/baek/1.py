

#i * 10 for i in range(20) if i % 3 ==0
#
#i + j for i in list1 for j in list2
#
#i for i in range(50) if i%2 == 0 and i%3 == 0
#
#i for i in range(50) if i%2 == 0 if i%3 == 0
#
#['even' if i%2 == 0 else 'odd' for i in range(10)]
#
#comprehension = [range(10)]

a, b = map(int, input().split())

print(next(comp for comp in ['<', '==', '>'] if (a < b and comp == '<') or (a == b and comp == '==') or (a > b and comp == '>')))