//
// Created by Zin Ko Winn on 8/28/2022.
//

#include <stdio.h>

int toDecimal(char hexadecimal[]);

void convert(int number, int format);

double power(double X, int Y);

void hexadecimalToOtherNumberSystem(char hexadecimal[], int format);

void showResult(int number, int format, int totalCount, int convertedValue[]);

int main() {
    char hexadecimalNumber[4] = "FEA9";
    hexadecimalToOtherNumberSystem(hexadecimalNumber, 2);
    hexadecimalToOtherNumberSystem(hexadecimalNumber, 8);
    hexadecimalToOtherNumberSystem(hexadecimalNumber, 10);
    return 0;
}

void hexadecimalToOtherNumberSystem(char hexadecimal[], int format) {
    int decimalNumber = toDecimal(hexadecimal);
    switch (format) {
        {
            case 2:
                convert(decimalNumber, format);
            break;
            case 8:
                convert(decimalNumber, format);
            break;
            case 10:
                printf("The decimal number of %d is %d", 2198, decimalNumber);
            break;
        }

    }
    printf("\n");
}

int toDecimal(char hexadecimal[]) {
    int currentNumber;
    int index = 0;
    int convertedNumber = 0;

    for (int i = (4 - 1); i >= 0; i--) {
        switch (hexadecimal[i]) {
            case 'A':
                currentNumber = 10;
                break;
            case 'B':
                currentNumber = 11;
                break;
            case 'C':
                currentNumber = 12;
                break;
            case 'D':
                currentNumber = 13;
                break;
            case 'E':
                currentNumber = 14;
                break;
            case 'F':
                currentNumber = 15;
                break;
            default:
                currentNumber = hexadecimal[i] - 0x30;
        }

        convertedNumber += (currentNumber) * power(16, index);
        index++;
    }
    return convertedNumber;
}

double power(double X, int Y) {
    double value = 1;
    for (int i = 0; i < Y; i++){
        value *= X;
    }
    return value;
}

void convert(int number, int format) {
    int convertedNumber[100];
    int index = 0;
    int decimalNumber = number;
    while (decimalNumber > 0) {
        int remainder = decimalNumber % format;
        convertedNumber[index] = remainder;
        decimalNumber /= format;
        index++;
    }
    showResult(number, format, index, convertedNumber);
}

void showResult(int number, int format, int totalCount, int convertedValue[]) {
    switch (format) {
        case 2:
            printf("The binary number of %d is ", number);
            break;
        case 8:
            printf("The octal number of %d is ", number);
            break;
    }

    for (int j = totalCount - 1; j >= 0; j--) {
        switch (format) {
            case 2:
                printf("%d", convertedValue[j]);
                break;
            case 8:
                printf("%d", convertedValue[j]);
        }
    }
}
