#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NAME "InputForSubmission_1.txt"

#define ARR_SIZE 10

_Bool arr[ARR_SIZE];

void initBoolArray(void)
{
	for (int i = 0; i < ARR_SIZE; i++) {
		arr[i] = false;
	}
}

_Bool checkBoolArray(void)
{
	for (int i = 0; i < ARR_SIZE; i++) {
		if ( arr[i] == false ) {
			return false;
		}
	}
	return true;
}

int checkSheepDigits(int number)
{
	int maeDigit = 0;
	int tempNumber = number;
	while (number != 0) {
		maeDigit = number%10;
		number = number/10;
		arr[maeDigit] = true;
	}
	if (checkBoolArray()) {
		return tempNumber;
	}
	else {
		return 0;
	}
}


int checkSheep(int digit)
{
	int n = 1;
	int result = 0;

	// Base case
	if ( digit == 0 ) {
		return 0;
	}
	while (true) {
		result = (n * digit);
		if ( checkSheepDigits(result) != 0 ) {
			return result;
		}
		n++;
	}

}

int main(void)
{

	int currentDigit = 0;
	int rn =0;
	char buffer[1024];

	// File to output
	FILE * oFile = fopen("output.txt", "w");

	// Open file and put digits
	FILE * fp = fopen(FILE_NAME, "r");

 	char * pch;
 	int val;
 	int n = 1;

    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	read = getline(&line, &len, fp);
    while ((read = getline(&line, &len, fp)) != -1) {
    	initBoolArray();
        currentDigit = atoi(line);
        printf("%d", currentDigit);
  		rn = checkSheep(currentDigit);
  		if (rn != 0 ) {
  			fprintf(oFile, "Case #%d: %d\n", n, rn );
  		}
  		else {
  			fprintf(oFile, "Case #%d: INSOMNIA \n", n);
  		}
  		n++;   
    }

}