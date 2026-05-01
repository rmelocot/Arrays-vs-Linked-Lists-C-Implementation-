#ifndef ARRAY_H
#define ARRAY_H

/* Structure Definition */
struct array
{
    int elements;	// # of elements currently existing in array
    int addr;		// # address of 1st element in array
};

/* Function Prototypes */
struct array *array_new (int size);

int array_get (struct array *ptr, int index);

void array_push (struct array *ptr, int value);

void array_append (struct array *ptr, int value);

void array_pop (struct array *ptr);

void array_truncate (struct array *ptr);

void array_free (struct array *ptr);

#endif
