#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int items[10]; 
}stack; 

stack* create_stack() {
    stack* new_stack = malloc(sizeof(stack)); 
    if(!new_stack) {
        printf((const char*)stderr, printf("malloc failure\n")); 
    }
    return new_stack; 
}

void push(stack* stack, int element) {
    for(int i = 0; i < sizeof(stack->items)/sizeof(stack->items[0]); i++) {
        if(!stack->items[i]) {
            stack->items[i] = element; 
            break; 
        }
        else if(i + 1 == sizeof(stack->items)/sizeof(stack->items[0])) {
            printf("Stack is full.\n"); 
            return; 
        }
    }
}

void pop(stack* stack) {
    for(int i = 0; i < sizeof(stack->items)/sizeof(stack->items[0]); i++) {
        if(!stack->items[i + 1]) {
            stack->items[i] = NULL; 
        }
    }
}

void print(stack* stack) {
    for(int i = 0; i < sizeof(stack->items)/sizeof(stack->items[0]); i++) {
        if(!stack->items[i]) {
            printf(". "); 
        }
        else {
            printf("%d ", stack->items[i]); 
        }
    }
    printf("\n"); 
}

int peek(stack* stack) {
    if(stack->items[0]) {
        return stack->items[0]; 
    }
    else {
        return -1; 
    }
}

int main() 
{
    stack* myStack = create_stack(); 
    push(myStack, 5); 
    push(myStack, 3); 
    push(myStack, 15); 
    print(myStack); 
    pop(myStack);
    print(myStack); 
    printf("%d ", peek(myStack)); 
}
