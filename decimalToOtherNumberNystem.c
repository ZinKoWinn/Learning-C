//
// Created by Zin Ko Winn on 8/28/2022.
//

#include <stdio.h>

char getHex(int value);

void decimalToOtherNumberSystem(int decimalNumber, int format);

void showResult(int decimalNumber, int format, int totalCount, int convertedValue[]);

int main() {
    printf("Decimal to other number system. \n");
    decimalToOtherNumberSystem(896, 2);
    decimalToOtherNumberSystem(896, 8);
    decimalToOtherNumberSystem(896, 16);
    return 0;
}

void decimalToOtherNumberSystem(int number, int format) {
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
    printf("\n");
}

void showResult(int number, int format, int totalCount, int convertedValue[]) {
    switch (format) {
        case 2:
            printf("The binary number of %d is ", number);
            break;
        case 8:
            printf("The octal number of %d is ", number);
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
            case 8:
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