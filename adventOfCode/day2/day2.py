import re

def validPassword(minNum: int, maxNum: int, char: chr, password: str)->bool:
    count = password.count(char)
    if(count >= minNum and count <= maxNum):
        return True
    return False    

def validPasswordPart2(minNum: int, maxNum: int, char: chr, password: str)->bool:
    if((password[minNum-1] == char) ^ (password[maxNum-1] == char)):
        return True
    return False
    
def main():
    # Read textfile
    f = open("input.txt", 'r')
    lines = f.readlines()
    p = re.compile("([0-9]*)-([0-9]*) ([a-z]{1}): ([a-z]*)")
    count = 0
    
    for line in lines:
        minNum = 0
        maxNum = 0
        char = ''
        password = ""
        
        group = p.match(line)
        minNum = int(group[1])
        maxNum = int(group[2])
        char = group[3]
        password = group[4]
        
        if (validPasswordPart2(minNum, maxNum, char, password)):
            count+=1
    
    print(count)

    
if __name__ == "__main__":
    main()
    
    