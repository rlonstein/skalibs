/* ISC license. */

#include "ttymodes.h"

int ttymodes_get (int fd, ttymodes_ref t)
{
  if (ttymodes_gett(fd, t) == -1) return -1 ;
  return ttymodes_getw(fd, t) ;
}
