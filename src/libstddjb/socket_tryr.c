/* ISC license. */

#include <sys/types.h>
#include <sys/socket.h>
#include "socket.h"

void socket_tryreservein (int s, unsigned int size)
{
  while (size >= 1024)
  {
    if (setsockopt(s, SOL_SOCKET, SO_RCVBUF, &size, sizeof size) == 0) return ;
    size -= (size >> 5) ;
  }
}
