class Human:
	name = ""
	age = 0
human = Human
human.name = input("氏名：")
human.age = int(input("年齢："))
miseinen = "成年" if human.age >= 18 else "未成年"
print(f'{human.name}は{miseinen}です！')
