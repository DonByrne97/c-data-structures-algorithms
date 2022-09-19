#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int key; 
    struct list_node* next; 
}list_node; 

typedef struct linked_list {
    list_node* head; 
    int size; 
}linked_list; 

list_node* create_node(int key) {
    list_node* new_node = malloc(sizeof(list_node)); 
    if(!new_node) {
        printf((const char*)stderr, "malloc failure\n"); 
    }
    new_node->key = key; 
    new_node->next = NULL; 
    return new_node; 
}

void insert_node(linked_list* list, int key) {
    list_node* new_node = create_node(key); 
    list_node* current = list->head; 
    if(!current) {
        list->head = new_node; 
    }
    else {
        while(current->next) {
            current = current->next; 
        }
        current->next = new_node; 
    }
    list->size++; 
}

void prepend_node(linked_list* list, int key) {
    list_node* new_node = create_node(key); 
    if(!list->head) {
        list->head = new_node; 
    }
    else {
        new_node->next = list->head; 
        list->head = new_node; 
    }
    list->size++; 
}

linked_list* create_linked_list(list_node* head) {
    linked_list* new_list = malloc(sizeof(linked_list)); 
    if(!new_list) {
        printf((const char*)stderr, printf("malloc failure\n")); 
    }
    new_list->head = head; 
    new_list->size = 1;  
    return new_list; 
}

void print_list(linked_list* list) {
    if(!list->head) {
        printf("List is null.\n");
    }
    else {
        list_node* current = list->head; 
        while(current) {
            printf("%d ", current->key); 
            current = current->next; 
        }
        printf("\n"); 
    }
}

void remove_at(linked_list* list, int index) {
    if(index == 0) {
        list->head = list->head->next; 
    }
    else {
        list_node* current = list->head; 
        list_node* prev = NULL; 
        for(int i = 0; i < index; i++) {
            prev = current; 
            current = current->next; 
        }   
        prev->next = current->next; 
        current->next = prev; 
    }
}

void remove_value(linked_list* list, int value) {
    if(list->head->key == value) {
        list->head = list->head->next; 
    }
    else {
        int i = 0; 
        list_node* current = list->head; 
        while(current && current->key != value) {
            current = current->next; 
            i++; 
        }
        if(current->key == value) {
            remove_at(list, i); 
        }
        else if(!current->next) {
            printf("Value not found in list.\n"); 
        }
    }
}

void free_list(linked_list* list) {
    list_node* current = list->head; 
    list_node* prev = NULL; 
    while(current) {
        prev = current; 
        current = current->next; 
        free(prev); 
    }
}

int main()
{
    list_node* head = create_node(5); 
    linked_list* myList = create_linked_list(head);
    prepend_node(myList, 3); 
    prepend_node(myList, 10); 
    insert_node(myList, 15); 
    print_list(myList); 
    remove_at(myList, 2); 
    print_list(myList); 
    remove_value(myList, 15); 
    print_list(myList); 
    remove_value(myList, 10); 
    print_list(myList); 
    free_list(myList); 
}
