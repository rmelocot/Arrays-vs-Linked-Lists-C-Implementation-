#ifndef LIST_H
#define LIST_H

struct list
{
   int head;		// address of element 1 in list
   int current;		// address of element used by some functions
};

/* Function Prototypes */
struct list *list_new (void);

void list_start (struct list *list);

void list_next (struct list *list);

int list_get (struct list *list);

void list_push (struct list * list, int value);

void list_append (struct list *list, int value);

void list_pop (struct list *list);

void list_truncate (struct list *list);

void list_free(struct list *list);

#endif
