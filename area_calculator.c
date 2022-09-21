//
// Created by Zin Ko Winn on 8/18/2022.
//

#include <stdio.h>

void calculateRectangleArea();

void calculateSquareArea();

void calculateTriangleArea();

void calculateCircleArea();

void calculateArea(int shapeType);

char startAgain();

int main() {
    int shapeType = 0;
    do {
        printf("WELCOME TO AREA CALCULATOR\n\n");

        printf("1. Rectangle\n");
        printf("2. Square\n");
        printf("3. Triangle\n");
        printf("4. Circle\n\n");
        printf("Choose shape to find area :  (1 or 2 or 3 or 4) : ");
        scanf("%d", &shapeType);
        printf("\n");
        calculateArea(shapeType);

    } while ((startAgain() == 'y'));

    return 0;
}


void calculateArea(int shapeType) {
    switch (shapeType) {
        case 1:
            calculateRectangleArea();
            break;
        case 2:
            calculateSquareArea();
            break;
        case 3:
            calculateTriangleArea();
            break;
        case 4:
            calculateCircleArea();
            break;
        default:
            printf("Invalid shape\n");
            break;
    }
}

void calculateRectangleArea() {
    int base = 0;
    int height = 0;
    printf("Enter the value of base : ");
    scanf("%d", &base);
    printf("Enter the value of height : ");
    scanf("%d", &height);
    int rectangleArea = base * height;
    printf("The area of the rectangle is : %d \n\n", rectangleArea);
}

void calculateSquareArea() {
    int length = 0;
    printf("Enter the value of length : ");
    scanf("%d", &length);
    int squareArea = length * length;
    printf("The area of the square is : %d \n\n", squareArea);
}

void calculateTriangleArea() {
    int base = 0;
    int height = 0;
    printf("Enter the value of base : ");
    scanf("%d", &base);
    printf("Enter the value of height : ");
    scanf("%d", &height);
    int triangleArea = (base * height) / 2;
    printf("The area of the triangle is : %d \n\n", triangleArea);
}

void calculateCircleArea() {
    // Area's circle is : π * r * r
    int radius = 0;
    printf("Enter the value of radius : ");
    scanf("%d", &radius);
    int circleArea = (3.14) * radius * radius;
    printf("The area of the circle is : %d \n\n", circleArea);
}

char startAgain() {
    printf("Do you want to calculate again? (y/n): ");
    char isStartAgain;
    scanf(" %c", &isStartAgain);
    return isStartAgain;
}