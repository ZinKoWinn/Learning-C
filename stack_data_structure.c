//
// Created by Zin Ko Winn on 20/9/2022.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int count = 0;

struct Stack {
    int array[MAX_SIZE];
    int top;
};

typedef struct Stack stack;

void createEmptyStack(stack *stackMemory) {
    stackMemory->top = -1;
}

int full(stack *s) {
    if (s->top == MAX_SIZE - 1)
        return 1;
    else
        return 0;

}

int empty(stack *s) {
    if (s->array[s->top] == -1) {
        return 1;
    }
    return 0;
}

void display(stack *s) {
    for (int i = 0; i < count; i++) {
        printf("%d : ", s->array[i]);
    }
    printf("\n\n");
}


void push(stack *s, int data) {
    if (full(s)) {
        printf("Our StackMemory is full!");
    } else {
        s->top++;
        s->array[s->top] = data;
        printf("Push Data : %d\n", data);
    }
    count++;
    printf("All data in our stack memory : \n");
    display(s);
}

void pop(stack *s) {
    if (empty(s)) {
        printf("Our StackMemory is empty!");
    } else {
        printf("Pop Data : %d\n", s->array[s->top]);
        s->top--;
    }
    count--;
    printf("All data in our stack memory : \n");
    display(s);
}

int main() {
    stack *stackMemory = (stack *) malloc(sizeof(stack));

    createEmptyStack(stackMemory);

    push(stackMemory, 101);
    push(stackMemory, 102);
    push(stackMemory, 103);
    push(stackMemory, 104);
    push(stackMemory, 105);

    pop(stackMemory);
    return 0;
}