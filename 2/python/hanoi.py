import copy

def push(list, obj):
	list.append(obj)
	return list
def pop(list):
	return list.pop(-1)

	'''	
[3,2,1]

1
2
3
	'''


class Hanoi():
	def __init__(self, n):
		self.tower = [[0],[0],[0]]
		self.tower[0] = [i for i in range(n, 0, -1)]
		
	def prt(self):
		tmp = copy.deepcopy(self.tower)
		for num, i in enumerate(tmp):
			if i == [0]:
				pop(tmp[num])
		
		m = max([len(i) for i in tmp])
		print(' |  |  | ')
		for i in range(m):
			for j in range(3):
				if len(tmp[j]) >= m-i:
					print('',tmp[j][-1],end=' ')
					pop(tmp[j])
				else:
					print(' |',end=' ')
			print()
		print('=========')
			
			
			
	def move(self, frm, to):
		if self.tower[frm][0] == 0:
			raise ValueError('none, sonzaishinai') 
			#存在しない
		elif self.tower[frm][-1] > self.tower[to][-1] and self.tower[to][-1] != 0:
			raise ValueError('contradiction, mujun')
			#矛盾
			
		elif self.tower[to][-1] == 0:
			pop(self.tower[to])
			push(self.tower[to], pop(self.tower[frm]))
		
		else:
			push(self.tower[to], pop(self.tower[frm]))

		if len(self.tower[frm]) == 0:
			push(self.tower[frm], 0)
		
		
		
	def isEnd(self):
		
			
hanoi = Hanoi(3)
print(hanoi.tower)
hanoi.prt()
print(hanoi.tower)
hanoi.move(0,1)
print(hanoi.tower)
hanoi.prt()