/* ISC license. */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "socket.h"

int socket_udp_internal (unsigned int flags)
{
  return socket_internal(AF_INET, SOCK_DGRAM, 0, flags) ;
}
