def ownMax(a,b,c):
	if a>=b and a>=c:
		return a
	elif b>=c and b>=a:
		return b
	elif c>=a and c>=b:
		return c

def ownMin(a,b,c):
	if a<=b and a<=c:
		return a
	elif b<=c and c<=a:
		return b
	elif c<=a and c<=b:
		return c


def ownSum(a,b,c):
	return a+b+c

def ownAvg(a,b,c):
	return ownSum(a,b,c)/3


a = float(input())
b = float(input())
c = float(input())
print("max: 1, min: 2, sum: 3, avg: 4")
flg = int(input())

if flg == 1:
	print(ownMax(a,b,c))
elif flg == 2:
	print(ownMin(a,b,c))
elif flg == 3:
	print(ownSum(a,b,c))
elif flg == 4:
	print(ownAvg(a,b,c))
