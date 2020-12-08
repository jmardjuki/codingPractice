def countForm(group:list)->int:
    count = 0
    ticks = set()
    entries = group.split("\n")
    for entry in entries:
        for char in entry:
            if char not in ticks:
                ticks.add(char)
                count+=1
    return count

def countForm2(group:list)->int:
    count = 0
    ticks = {}
    entries = group.split("\n")
    numOfPeople = len(entries)
    for entry in entries:
        if numOfPeople == 1:
            return len(entry)
        for char in entry:
            if char not in ticks:
                ticks[char] = 1
            else:
                ticks[char]+=1
                if ticks[char] == numOfPeople:
                    count+=1
    return count

def main():
    f = open("input.txt", 'r')
    lines = f.read()
    groups = lines.split("\n\n")
    result = 0
    result2 = 0
    for group in groups:
        result += countForm(group)
        result2 += countForm2(group)
    print(result)
    print(result2)

if __name__ == "__main__":
    main()