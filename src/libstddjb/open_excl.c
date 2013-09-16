/* ISC license. */

#include <sys/types.h>
#include <fcntl.h>
#include "djbunix.h"

int open_excl (char const *fn)
{
  return open3(fn, O_WRONLY | O_CREAT | O_EXCL | O_NDELAY, 0666) ;
}
