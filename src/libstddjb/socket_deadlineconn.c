/* ISC license. */

#include <errno.h>
#include "uint16.h"
#include "error.h"
#include "tai.h"
#include "iopause.h"
#include "socket.h"

int socket_deadlineconn (int s, char const *ip, uint16 port, struct taia const *deadline)
{
  if (socket_connect4(s, ip, port) == -1)
  {
    iopause_fd x = { s, IOPAUSE_WRITE | IOPAUSE_EXCEPT, 0 } ;
    if (!error_isagain(errno) && !error_isalready(errno)) return -1 ;
    for (;;)
    {
      struct taia stamp ;
      taia_now(&stamp) ;
      switch (iopause(&x, 1, deadline, &stamp))
      {
        case -1 : return -1 ;
        case 0 : return (errno = ETIMEDOUT, 0) ;
      }
      if (x.revents & IOPAUSE_EXCEPT) return -1 ;
      if (x.revents & IOPAUSE_WRITE) break ;
    }
    if (!socket_connected(s)) return -1 ;
  }
  return 1 ;
}
