import sys
print("1つ目の自然数を入力：", end="")
i = int(input())
print("2つ目の自然数を入力：", end="")
n = int(input())

if i<0:
	print("自然数(0より大きな整数)以外が入力されました！")
	sys.exit()

if i == n:
	print("同じ自然数が入力されました！")
	sys.exit()

def s(i, n):
	tmp = 0
	for j in range(i,n+1):
		tmp += j 
	return tmp

def m(i,n):
	tmp = 1
	for j in range(i,n+1):
		tmp *= j
	return tmp

print(f'{i}から{n}までの全整数の和は',end="")
print(s(i,n))
print(f'{i}から{n}までの全整数の積は',end="")
print(m(i,n))

