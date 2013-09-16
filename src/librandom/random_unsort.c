/* ISC license. */

#include <errno.h>
#include "bytestr.h"
#include "random.h"

int random_unsort (char *s, unsigned int n, unsigned int chunksize)
{
  char tmp[4096] ;
  if (chunksize > 4096) return (errno = EMSGSIZE, 0) ;
  while (n--)
  {
    register unsigned int i = badrandom_int(n+1) ;
    byte_copy(tmp, chunksize, s + i * chunksize) ;
    byte_copy(s + i * chunksize, chunksize, s + n * chunksize) ;
    byte_copy(s + n * chunksize, chunksize, tmp) ;
  }
  return 1 ;
}
