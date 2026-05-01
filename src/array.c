#include "array.h"
#include "mem.h"
#include <stdio.h>
#include <stdlib.h>

struct array *array_new (int size) {
    struct array * arr;
    arr = malloc( sizeof(struct array) ); // allocate memory for array

    arr -> elements = 0;                  // set # elements to 0
    arr -> addr = mem_alloc(size);        // get addr of first element

    return arr;
}

int array_get (struct array *ptr, int index){    
    if (index < 0 || index >= ptr->elements) {
        // Index out of bounds
        return 0;
    }

    int addr;                           
    addr = ptr->addr + index;           // take address of 1st element and add index value

    return get_value(addr);            // return the value at this sum
}

void array_push(struct array *ptr, int value){
    // push each element one position down
    // starting @ end of array & derementing towards start

    int addr, size;
    addr = ptr->addr;
    size = ptr->elements;

    for (int i = size -1; i >= 0; i--){	  // decremenet until all values moved
        int val;
        val = get_value(addr+i);   // return val @ each index

        // place value at the next index
        set_value(addr + i +1, val);
    }

    set_value(addr, value); // add new val oto array start
    ptr->elements++;	// increment num of elements

}


void array_append(struct array *ptr, int value) {
    int nextAddr;
    nextAddr = ptr->addr + ptr->elements;   // next free address

    set_value(nextAddr, value); // add new value

    ptr->elements++;    // increment array elements
}

void array_pop(struct array *ptr) {
    if(!(ptr->elements == 0)){

        for (int i = 0; i < ptr->elements - 1; i++){
            int val;
            val = get_value(ptr->addr + (i+1));
            set_value(ptr->addr + i, val);
        }

        ptr->elements--;	//decrement # elements
    }
    return;
}

void array_truncate(struct array *ptr) {
    if (!(ptr->elements == 0)) {
        ptr->elements--; 
    }
    return;
}

void array_free (struct array *ptr) {
    if (!(ptr == NULL)){
        mem_free(ptr->addr);
        free(ptr); // free memory

    }
}
