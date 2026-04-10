
def main():
	point = 50
	zero_count = 0
	with open("input1.txt") as file:
		for line in file:
			direction = line[0]
			num = line[1:]
			if direction == 'R':
				point = (point + int(num))%100
			elif direction == "L":
				point = (point - int(num))%100
			if point == 0:
				zero_count +=1
	print(zero_count)


if __name__== "__main__":
	main()
