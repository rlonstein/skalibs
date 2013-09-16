/* ISC license. */

#include <sys/types.h>
#include <fcntl.h>
#include "djbunix.h"

int open_write (char const *fn)
{
  return open2(fn, O_WRONLY | O_NDELAY) ;
}
