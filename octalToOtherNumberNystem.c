//
// Created by Zin Ko Winn on 8/28/2022.
//

#include <stdio.h>

char getHex(int value);

double power(double X, int Y);

int toDecimal(int octal);

void convert(int number, int format);

void octalToOtherNumberSystem(int decimalNumber, int format);

void showResult(int number, int format, int totalCount, int convertedValue[]);

int main() {
    printf("Octal to other number system. \n");
    octalToOtherNumberSystem(144, 2);
    octalToOtherNumberSystem(144, 10);
    octalToOtherNumberSystem(144, 16);
    return 0;
}

void octalToOtherNumberSystem(int number, int format) {
    switch (format) {
        {
            case 2:
                convert(number, format);
            break;
            case 10:
                printf("The decimal number of %d is %d", number, toDecimal(number));
            break;
            case 16:
                convert(number, format);
            break;
        }

    }
    printf("\n");
}

int toDecimal(int octal) {
    int convertedNumber = 0;
    int index = 0;
    int octalNumber = octal;
    while (octalNumber > 0) {
        int remainder = octalNumber % 10;
        convertedNumber += remainder * power(8, index);
        octalNumber /= 10;
        index++;
    }
    return convertedNumber;
}

void convert(int number, int format) {
    int convertedNumber[100];
    int index = 0;
    int decimalNumber = toDecimal(number);
    while (decimalNumber > 0) {
        int remainder = decimalNumber % format;
        convertedNumber[index] = remainder;
        decimalNumber /= format;
        index++;
    }
    showResult(number, format, index, convertedNumber);
}

double power(double X, int Y) {
    double value = 1;
    for (int i = 0; i < Y; i++) {
        value *= X;
    }
    return value;
}

void showResult(int number, int format, int totalCount, int convertedValue[]) {
    switch (format) {
        case 2:
            printf("The binary number of %d is ", number);
            break;
        case 16:
            printf("The hexadecimal number of %d is ", number);
            break;
    }

    for (int j = totalCount - 1; j >= 0; j--) {
        switch (format) {
            case 2:
                printf("%d", convertedValue[j]);
                break;
            case 16:
                printf("%c", getHex(convertedValue[j]));
                break;
        }
    }
}


char getHex(int value) {
    char values[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    return values[value];
}