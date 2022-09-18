#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int contents[10]; 
}queue; 

queue* create_queue() {
    queue* new_queue = malloc(sizeof(queue)); 
    return new_queue; 
}

int is_empty(queue* queue) {
    for(int i = 0; i < sizeof(queue->contents)/sizeof(queue->contents[0]); i++) {
        if(!queue->contents[i] && queue->contents[i + 1] > sizeof(queue->contents)/sizeof(queue->contents[0])) {
            return 1; 
        }
        else if(queue->contents[i]) {
            return 0; 
        }
    }
    return 0; 
}

void enqueue(queue* queue, int element) {
    for(int i = 0; i < sizeof(queue->contents)/sizeof(queue->contents[0]); i++) {
        if(!queue->contents[i]) {
            queue->contents[i] = element; 
            break; 
        }
        else if(i + 1 == sizeof(queue->contents)/sizeof(queue->contents[0])) {
            printf("Queue is full.\n"); 
            return; 
        }
    }
}

void dequeue(queue* queue) {
    if(queue->contents[0]) {
        for(int i = 1; i < sizeof(queue->contents)/sizeof(queue->contents[0]); i++) {
            queue->contents[i - 1] = queue->contents[i]; 
        }
    }
    else {
        printf("Nothing to dequeue.\n"); 
    }
}

void print_queue(queue* queue) {
    for(int i = 0; i < sizeof(queue->contents)/sizeof(queue->contents[0]); i++) {
        if(queue->contents[i]) {
            printf("%d ", queue->contents[i]); 
        }
        else {
            printf(". "); 
        }
    }
    printf("\n"); 
}

int peek(queue* queue) {
    if(queue->contents[0]) {
        return queue->contents[0]; 
    }
}

int main()
{
    queue* myQueue = create_queue();
    printf("%d\n", is_empty(myQueue)); 
    enqueue(myQueue, 10); 
    enqueue(myQueue, 20); 
    enqueue(myQueue, 30); 
    print_queue(myQueue); 
    printf("%d\n", is_empty(myQueue)); 
    dequeue(myQueue); 
    print_queue(myQueue); 
}
