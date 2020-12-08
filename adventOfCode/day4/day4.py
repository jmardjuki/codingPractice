def checkValidity(detail:list)->bool:
    mandatory = {'byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid'}
    for val in detail:
        val = val.split(":")
        if val[0] in mandatory:
            mandatory.remove(val[0])
    if len(mandatory) > 0:
        return False
    return True

def part1(details:list)->int:
    count = 0
    for detail in details:
        detail = detail.split()
        if checkValidity(detail):
            count += 1
    return count

def main():
    # Read textfile
    f = open("input.txt", 'r')
    lines = f.read()
    lines = lines.split("\n\n")
        
    print(part1(lines))    
    
if __name__ == "__main__":
    main()
    
    