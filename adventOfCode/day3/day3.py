def part1(lines:list, step:int, rightStep:int)->int:
    rightShift = 0
    rightMax = len(lines[0])
    count = 0
    for i in (range(0, len(lines), step)):
        if (lines[i][rightShift] == "#"):
            count +=1   
        rightShift += rightStep
        rightShift = rightShift%rightMax
    return count
   

def main():
    # Read textfile
    f = open("input.txt", 'r')
    lines = f.read()
    lines = lines.split("\n")

    # Part 1
    print(part1(lines, 1, 3))
    # Part 2
    print((part1(lines, 1, 1) *
            part1(lines, 1, 3) *
            part1(lines, 1, 5) *
            part1(lines, 1, 7) *
            part1(lines, 2, 1)))
    
    
if __name__ == "__main__":
    main()
    
    