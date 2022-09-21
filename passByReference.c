//
// Created by Zin Ko Winn on 8/30/2022.
//

#include "stdio.h"

void myFun(int *a, int *b);

int main() {

    int firstData = 0;
    int secondData = 0;

    printf("Enter first Value:");
    scanf("%d", &firstData);

    printf("Enter Second value:");
    scanf("%d", &secondData);

    printf("Before Passing firstData = %d , SecondData = %d ", firstData, secondData);

    myFun(&firstData, &secondData);

    printf("\nAfter Passing firstData = %d , SecondData = %d \n", firstData, secondData);

    return 0;
}

void myFun(int *a, int *b) {

    int temp = *a * 10;
    *a = *b * 10;
    *b = temp;
}