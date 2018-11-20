def recurrence(arr):
    mySet = set()
    for char in arr:
        if char not in mySet:
            mySet.add(char)
        else:
            return char
    return None

def nonRecurrence(arr):
    key = {}
    myMin = -1
    tempChar =""
    for i in range(len(arr)):
        if arr[i] not in key:
            key[arr[i]] = i
        else:
            key[arr[i]] = -1
    for i in range(len(key)):
        if key[arr[i]] != -1:
            if myMin == -1:
                myMin = key[arr[i]]
                tempChar = arr[i]
            if key[arr[i]] < myMin:
                tempChar = arr[i]
    return tempChar

def main():
    arr = "ABCA"
    print(nonRecurrence(arr))
    arr = "BCABA"
    print(nonRecurrence(arr))
    arr = "ABC"
    print(nonRecurrence(arr))
    arr = ""
    print(nonRecurrence(arr))
    arr = "AAAA"
    print(nonRecurrence(arr))


if __name__ == "__main__":
    main()
