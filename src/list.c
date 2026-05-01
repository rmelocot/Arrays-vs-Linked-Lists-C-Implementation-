#include "list.h"
#include "mem.h" 
#include <stdlib.h>

struct list *list_new(void) { 
    struct list * ptr; 
    ptr = malloc(sizeof(struct list)); 
    ptr -> head = 0; ptr -> current = 0; 

    return ptr; 
}

void list_start( struct list *list ){ 
    if (!(list == NULL)){ 
        list->current = list->head; 
    } 
}

void list_next(struct list *list) {
    if (list && list->current != 0) {
        list->current = get_next(list->current + 1);  // look at +1
    }
}

int list_get( struct list *list ){ 
    if(list->current == 0){ 
        return -1; 
    } 
    return get_value(list->current); 
}

void list_push(struct list *list, int value) {
    int addr = mem_alloc(2);              //allocate two blocks of memory
    set_value(addr, value);               
    set_next(addr + 1, list->head);       
    list->head = addr;                    
}

void list_append(struct list *list, int value) {
    int addr = mem_alloc(2);
    set_value(addr, value);
    set_next(addr + 1, 0);                // NULL

    if (list->head == 0) {
        list->head = addr;
    } else {
        int a = list->head;
        while (get_next(a + 1) != 0) {  // looks @ addr + 1
            a = get_next(a + 1);
        }
        set_next(a + 1, addr);          // link @ a+1
    }
}

void list_pop(struct list *list) {
    if (list->head != 0) {
        int next;
        next = get_next(list->head + 1);   
        mem_free(list->head);                 // free 2 blocks node
        list->head = next;
    }
}

// undo append operation
void list_truncate(struct list *list) {
    if (!(list->head == 0)){

        int a, prev;
        a = list->head;
        prev = 0;

        while (get_next(a + 1) != 0) {
            prev = a;
            a = get_next(a + 1);
        }

        if (prev != 0) {
            set_next(prev + 1, 0);
        } else {
            list->head = 0;
        }

        mem_free(a);
    }
}
void list_free(struct list *list) {
    if (list->head != 0) {
        int a, next;

        a = list->head;
        next = get_next(a+1);

        // move head forward. this allows recursive call to work
        list->head = next;

        mem_free(a);
        list_free(list);  // recursive call
    } else {
        free(list);  // free list from memory
    }
}
