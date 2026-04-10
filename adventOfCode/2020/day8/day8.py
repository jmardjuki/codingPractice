import re

def runInstruction(lines:list)->int:
    accNum = 0
    i = 0
    visited = set()
    p = re.compile("([a-z]{3}) ([-+])([0-9]*)")
    while(True):
        if i in visited:
            break
        visited.add(i)
        group = p.match(lines[i])
        
        opcode = group[1]
        operand = group[2]
        arg = group[3]
        
        if opcode == 'nop':
            i+=1
        elif opcode == 'acc':
            accNum = eval(str(accNum) + operand + arg)
            i+=1
        elif opcode == 'jmp':
            i = eval(str(i) + operand + arg)
    
    return accNum
    

def main():
    # Read textfile
    f = open("input.txt", 'r')
    lines = f.read()
    lines = lines.split("\n")
        
    print(runInstruction(lines))    
    
if __name__ == "__main__":
    main()