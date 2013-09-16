/* ISC license. */

#include "sysdeps.h"
#include "skalibs-config.h"

#if defined(HASIPV6) && defined(SKALIBS_FLAG_WANTIPV6)

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "uint16.h"
#include "bytestr.h"
#include "socket.h"

int socket_bind6 (int s, char const *ip6, uint16 port)
{
  struct sockaddr_in6 sa ;
  byte_zero(&sa, sizeof sa) ;
  sa.sin6_family = AF_INET6 ;
  uint16_pack_big((char *)&sa.sin6_port, port) ;
  byte_copy(sa.sin6_addr.s6_addr, 16, ip6) ;
  return bind(s, (struct sockaddr *)&sa, sizeof sa) ;
}

#else

#include <errno.h>
#include "uint16.h"
#include "socket.h"

int socket_bind6 (int s, char const *ip6, uint16 port)
{
  (void)s ;
  (void)ip6 ;
  (void)port ;
  return (errno = ENOSYS, -1) ;
}

#endif
