/* ISC license. */

#include <errno.h>
#include "error.h"
#include "uint16.h"
#include "tai.h"
#include "iopause.h"
#include "socket.h"

int socket_recvnb4 (int s, char *buf, unsigned int len, char *ip, uint16 *port, struct taia const *deadline, struct taia *stamp)
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
      r = socket_recv4(s, buf, len, ip, port) ;
      if (r < 0)
      {
        if (!error_isagain(errno)) return -1 ;
      }
      else return r ;
    }
  }
}
