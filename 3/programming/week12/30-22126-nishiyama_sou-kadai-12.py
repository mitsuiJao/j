a = 1
b = 1

print("同じ値の識別子")
print(id(a))
print(id(b))
print()

b = 2
print("異なる値の識別子")
print(id(a))
print(id(b))
print()

arr1 = [1,2,3,4,5]
arr2 = arr1
print("配列を代入でコピーした識別子")
print(id(arr1))
print(id(arr2))
print()

arr1[0] = 100
print("一方を変更するともう一方も変更される")
print(arr1[0])
print(arr2[0])
print()


import copy
arr1 = [1,2,3,4,5]
arr2 = copy.copy(arr1)
print("配列をcopy.copy()でコピーした識別子")
print(id(arr1))
print(id(arr2))
print()

arr1[0] = 100
print("一方を変更してももう一方は変更されない")
print(arr1[0])
print(arr2[0])

