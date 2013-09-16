/* ISC license. */

#include <sys/types.h>
#include <fcntl.h>
#include "djbunix.h"

int open_read (char const *fn)
{
  return open2(fn, O_RDONLY | O_NDELAY) ;
}
