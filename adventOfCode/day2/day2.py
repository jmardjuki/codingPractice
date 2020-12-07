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
    
    count = 0
    
    for line in lines:
        minNum = 0
        maxNum = 0
        char = ''
        password = ""
        
        rest, char, password = line.strip().split(" ")
        char = char.replace(":", "")
        rest = rest.split("-")
        minNum = int(rest[0])
        maxNum = int(rest[1])
        
        if (validPasswordPart2(minNum, maxNum, char, password)):
            count+=1
    
    print(count)

    
if __name__ == "__main__":
    main()
    
    