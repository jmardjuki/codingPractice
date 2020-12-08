def part1(desiredNum:int, lines: list)->int:
    numSet = set()
    for val in lines:
        myNum = int(val)
        if (desiredNum - myNum) in numSet:
            return((desiredNum - myNum)*myNum)
        else:
            numSet.add(myNum)
    return 0

def part2(desiredNum:int, lines:list)->int:
    # desiredNum = x + y + z
    numSetX = set()
    for i in range(len(lines)):
        val1 = int(lines[i])
        for j in range(i, len(lines)):
            val2 = int(lines[j])
            if (desiredNum -val1 - val2) in numSetX:
                return (desiredNum - val1 - val2)*val1*val2
            else:
                numSetX.add(val2)
    return 0


def main():
    f = open("input.txt", 'r')
    lines = f.read()
    lines = lines.split("\n")
    
    print(part1(2020, lines))
    print(part2(2020, lines))

if __name__ == "__main__":
    main()