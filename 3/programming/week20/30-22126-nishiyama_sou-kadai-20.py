string = "Hello world!\nPython\nfile manage test"

with open("test", mode="w") as f:
	f.write(string)

with open("test", mode="r") as f:
	s = f.read()
	print(s)

with open("test", mode="r") as f:
	arr = f.readlines() # <'list'>
	print(arr)

with open("test", mode="r") as f:
	for l in f:
		print(l)
