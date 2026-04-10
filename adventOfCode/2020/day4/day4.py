import re

def checkItemValidity(val:list)->bool:
    if val[0] == 'byr':
        byr = int(val[1])
        if byr <= 2002 and byr >= 1920:
            return True
    if val[0] == 'iyr':
        iyr = int(val[1])
        if iyr <= 2020 and iyr >= 2010:
            return True
    if val[0] == 'eyr':
        eyr = int(val[1])
        if eyr <= 2030 and eyr >= 2020:
            return True
    if val[0] == 'hgt':
        hgt = val[1]
        p = re.compile("(.[0-9]*)(.[a-z]*)")
        result = p.search(hgt)
        height = int(result.group(1))
        unit = result.group(2)
        if (unit == "cm"):
            if(height >= 150 and height <= 193):
                return True
        elif (unit == "in"):
            if(height >= 59 and height <= 76):
                return True
    if val[0] == 'hcl':
        p = re.compile("#[0-9a-f]{6}")
        result = p.search(val[1])
        if result:
            return True
    if val[0] == 'ecl':
        colourValid = {'amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'}
        if val[1] in colourValid:
            return True
    if val[0] == 'pid':
        p = re.compile("[0-9]{9}")
        result = p.search(val[1])
        if result and len(val[1]) == 9:
            return True

    return False
        

def checkValidity(detail:list)->bool:
    mandatory = {'byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid'}
    for val in detail:
        val = val.split(":")
        if val[0] in mandatory:
            if(checkItemValidity(val)):
                mandatory.remove(val[0])
    if len(mandatory) > 0:
        return False
    return True

def part(details:list)->int:
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
        
    print(part(lines))    
    
if __name__ == "__main__":
    main()
    
    