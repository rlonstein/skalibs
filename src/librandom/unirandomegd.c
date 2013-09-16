/* ISC license. */

#include <errno.h>
#include "djbunix.h"
#include "randomegd.h"
#include "unirandom.h"
#include "unirandomegd.h"

int unirandomegd_sinit (union unirandominfo *u, char const *path)
{
  int s = randomegd_open(path) ;
  if (s == -1) return 0 ;
  if (coe(s) == -1)
  {
    register int e = errno ;
    fd_close(s) ;
    errno = e ;
    return 0 ;
  }
  u->file.fd = s ;
  u->file.nb = 0 ;
  return 1 ;
}

int unirandomegd_finish (union unirandominfo *u)
{
  if (fd_close(u->file.fd) == -1) return 0 ;
  return 1 ;
}

unsigned int unirandomegd_readb (union unirandominfo *u, char *s, unsigned int n)
{
  return randomegd_readb(u->file.fd, s, n) ;
}

unsigned int unirandomegd_readnb (union unirandominfo *u, char *s, unsigned int n)
{
  return randomegd_readnb(u->file.fd, s, n) ;
}
