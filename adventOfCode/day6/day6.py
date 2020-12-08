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
        

def main():
    f = open("input.txt", 'r')
    lines = f.read()
    groups = lines.split("\n\n")
    result = 0
    for group in groups:
        result += countForm(group)
    print(result)

if __name__ == "__main__":
    main()