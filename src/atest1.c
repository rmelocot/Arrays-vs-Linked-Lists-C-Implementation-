/* atest1
 * This program tests an array's abilities and speed to add items at the
 * beginning.
 * Professor S.C.Kremer, 2026
 */

#include <stdio.h>

#include "mem.h"
#include "array.h"

int main( int argc, char **argv )
{
  struct array *array;

  reset_counters();
  array = array_new( 100 );

  // The following loop adds elements at index 0 in the array.
  // To do this it must move all other elements one position down
  // moving an element 1 position takes 2 dereferences (one to retreive the
  // value; one to store it again).
  // Adding one element takes only 1 dereferences (just store the value).
  // Adding the second element takes 3 dereferences (one read, two writes).
  // Adding the third element takes 5 deferences(two reads, three writes).
  // The total number of dereferences required to add element n is:
  //   d(n) = 2*(n-1)+1
  // And the cumulateive number of dereferences (from the latest addition 
  // and all previous) should follow the formula:
  //   d(n) = 2*(n-1)+1 + d(n-1)
  //        = n^2
  // Look for the n^2 pattern in the table created.
  printf( COUNTER_HEADINGS );
  for (int i=0;i<100;i++)	// count from 0 to 99 (inclusive)
  {
    if (i%10==0 || i<=10)	// every 10 steps
    {
      print_counters( i );	// display the counters
    }

    array_push( array, 99-i );	// add numbers at beginning of array in
				// decreasing order so smallest number is
				// always at index 0
  }
  print_counters( 100 );	// display the counters

  for (int i=0;i<100;i++)
  {
    int value;
    value = array_get( array, i );
    if (value!=i)
    {
      printf( "Incorrect value detected array[%d]=%d != %d\n", i, value, i );
    }
  }

  // array_free( array );
  array_free( array );

  // this should add 100 dereferences to check the values in the previous loop
  // and one call to mem_free
  print_counters( 100 );
  return 1;
}
