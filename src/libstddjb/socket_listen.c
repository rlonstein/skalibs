/* ISC license. */

#include <sys/types.h>
#include <sys/socket.h>
#include "socket.h"

int socket_listen (int s, int backlog)
{
  return listen(s, backlog) ;
}
