/* ISC license. */

#include "ttymodes.h"

int ttymodes_set_nohang (int fd, ttymodes const *t)
{
  if (ttymodes_sett_nohang(fd, t) == -1) return -1 ;
  return ttymodes_setw(fd, t) ;
}
