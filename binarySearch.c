//
// Created by Zin Ko Winn on 21/9/2022.
//

#include <stdio.h>

char isExit();

int binarySearch(int dataArray[], int toFindData, int low, int high);

int main() {
    int toFind = 0;
    int data[] = {1, 5, 6, 7, 8, 10, 20, 30, 40, 100, 200, 300};

    printf("WELCOME FROM BINARY SEARCH PROGRAM\n\n");

    do {
        printf("Enter data to find:");
        scanf("%d", &toFind);

        int size = sizeof(data) / sizeof(data[0]);
        int result = binarySearch(data, toFind, 0, size - 1);

        if (result == -1)
            printf("Not found data\n");
        else
            printf("Data found at index number : %d\n", result);
    } while (isExit() != 'y');
    return 0;
}


int binarySearch(int dataArray[], int toFindData, int low, int high) {

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (dataArray[mid] == toFindData)
            return mid;

        if (dataArray[mid] < toFindData)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

char isExit() {
    char isExist;
    printf("Do you want to exit? (y/n) : ");
    scanf(" %c", &isExist);
    return isExist;
}

