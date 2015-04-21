import sys

D = ["U", "R", "D", "L"]
length, d = 1, 0

while True:
	for i in range(length):
		print(D[d])
		sys.stdout.flush()
		response = input().rstrip()
		if response in ["Y", "E"]:
			exit(0)
	d = (d + 1) % len(D)

	for i in range(length):
		print(D[d])
		sys.stdout.flush()
		response = input().rstrip()
		if response in ["Y", "E"]:
			exit(0)
	d = (d + 1) % len(D)
	length += 1