*/
/* ltest1
 * This program tests a linked list's abilities and speed to add items at the
 * beginning.
 * S.C.Kremer, 2025
 */

#include <stdio.h>

#include "mem.h"
#include "list.h"

int main( int argc, char **argv )
{
  struct list *list;

  reset_counters();
  list = list_new();

  // The following loop adds elements at index 0 in the list.
  // To do this it can simple add an item at the top of the list.
  // Each itemn requires one memory allocation, one reference to set the
  // value of the node, and one reference to make the next pointer in the node
  // point to the previous head of the list.
  // The total number of dereferences required to add element n is:
  //   d(n) = 2
  // And the cumulateive number of dereferences (from the latest addition 
  // and all previous) should follow the formula:
  //   d(n) = 2*n
  //        = n^2
  // Look for the 2n pattern in the table created.
  printf( COUNTER_HEADINGS );
  for (int i=0;i<100;i++)	// count from 0 to 99 (inclusive)
  {
    if (i%10==0 || i<=10)	// every 10 steps
    {
      print_counters( i );	// display the counters
    }

    list_push( list, 99-i );	// add numbers at beginning of list in
				// decreasing order so smallest number is
				// always at index 0
  }
  print_counters( 100 );	// display the counters

  list_start( list );
  for (int i=0;i<100;i++)
  {
    int value;
    value = list_get( list );
    if (value!=i)
    {
      printf( "Incorrect value detected list[%d]=%d != %d\n", i, value, i );
    }
    list_next( list );
  }

  list_free( list );

  // this should add 100 dereferences to check the values in the previous loop
  // and one call to mem_free
  print_counters( 100 );
  return 1;
}

