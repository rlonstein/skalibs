/* ISC license. */

#include <errno.h>
#include "allreadwrite.h"
#include "djbunix.h"
#include "unirandom.h"
#include "unirandomdev.h"

int unirandomdev_sinit (union unirandominfo *u, char const *file)
{
  int fd = open_read(file) ;
  if (fd == -1) return 0 ;
  if (coe(fd) == -1)
  {
    register int e = errno ;
    fd_close(fd) ;
    errno = e ;
    return 0 ;
  }
  u->file.fd = fd ;
  u->file.nb = 1 ;
  return 1 ;
}

int unirandomdev_finish (union unirandominfo *u)
{
  if (fd_close(u->file.fd) == -1) return 0 ;
  return 1 ;
}

unsigned int unirandomdev_readb (union unirandominfo *u, char *s, unsigned int n)
{
  if (u->file.nb)
  {
    if (ndelay_off(u->file.fd) == -1) return 0 ;
    u->file.nb = 0 ;
  }
  return allread(u->file.fd, s, n) ;
}

unsigned int unirandomdev_readnb (union unirandominfo *u, char *s, unsigned int n)
{
  if (!u->file.nb)
  {
    if (ndelay_on(u->file.fd) == -1) return 0 ;
    u->file.nb = 1 ;
  }
  return allread(u->file.fd, s, n) ;
}
