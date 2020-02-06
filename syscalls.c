
/* for caddr_t (typedef char * caddr_t;) */
#include <sys/types.h>

extern int  __HEAP_START;


caddr_t _sbrk ( int a, int incr )
{
  static unsigned char *heap = NULL;
  unsigned char *prev_heap;

  if (heap == NULL)
  {
    heap = (unsigned char *)&__HEAP_START;
  }

  prev_heap = heap;
  /* check removed to show basic approach */

  heap += incr;

  return (caddr_t) prev_heap;
}
