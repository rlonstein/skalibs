/* ISC license. */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "uint16.h"
#include "bytestr.h"
#include "socket.h"

int socket_bind4 (int s, char const *ip, uint16 port)
{
  struct sockaddr_in sa ;
  byte_zero(&sa, sizeof sa) ;
  sa.sin_family = AF_INET ;
  uint16_pack_big((char *)&sa.sin_port, port) ;
  byte_copy((char *)&sa.sin_addr, 4, ip) ;
  return bind(s, (struct sockaddr *)&sa, sizeof sa) ;
}
