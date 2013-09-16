/* ISC license. */

#include "sysdeps.h"
#include "skalibs-config.h"

#if defined(HASIPV6) && defined(SKALIBS_FLAG_WANTIPV6)

#include <errno.h>
#include "error.h"
#include "uint16.h"
#include "tai.h"
#include "iopause.h"
#include "socket.h"

int socket_recvnb6 (int s, char *buf, unsigned int len, char *ip6, uint16 *port, struct taia const *deadline, struct taia *stamp)
{
  iopause_fd x = { s, IOPAUSE_READ, 0 } ;
  for (;;)
  {
    register int r = iopause_stamp(&x, 1, deadline, stamp) ;
    if (r < 0) return -1 ;
    if (!r) return (errno = ETIMEDOUT, -1) ;
    if (x.revents & IOPAUSE_EXCEPT) return (errno = EIO, -1) ;
    if (x.revents & IOPAUSE_READ)
    {
      r = socket_recv6(s, buf, len, ip6, port) ;
      if (r < 0)
      {
        if (!error_isagain(errno)) return -1 ;
      }
      else return r ;
    }
  }
}

#else

#include <errno.h>
#include "uint16.h"
#include "tai.h"

int socket_recvnb6 (int s, char *buf, unsigned int len, char *ip6, uint16 port, struct taia const *deadline, struct taia *stamp)
{
  (void)s ;
  (void)buf ;
  (void)len ;
  (void)ip6 ;
  (void)port ;
  (void)deadline ;
  (void)stamp ;
  return (errno = ENOSYS, -1) ;
}

#endif
