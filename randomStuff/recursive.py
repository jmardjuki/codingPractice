# Python
def balance(t):
    # Initial balance is 25
    if ( t == 0):
        return 25
    else:
        return balance(t-1)+10

def factorial(num):
    if ( num == 1):
        return 1;
    else:
        return factorial(num-1)*num

def quadratic(num, factor):
    if (factor == 1):
        return num
    else:
        return quadratic(num, factor-1)*num

def main():
    print(balance(3))
    print(factorial(9))
    print(quadratic(4,5))


if __name__ == "__main__":
    main()
