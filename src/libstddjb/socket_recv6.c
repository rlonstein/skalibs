/* ISC license. */

#include "sysdeps.h"
#include "skalibs-config.h"

#if defined(HASIPV6) && defined(SKALIBS_FLAG_WANTIPV6)

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include "uint16.h"
#include "bytestr.h"
#include "socket.h"

int socket_recv6 (int s, char *buf, unsigned int len, char *ip6, uint16 *port)
{
  struct sockaddr_in6 sa ;
  socklen_t dummy = sizeof sa ;
  register int r ;
  do r = recvfrom(s, buf, len, 0, (struct sockaddr *)&sa, &dummy) ;
  while ((r == -1) && (errno == EINTR)) ;
  if (r == -1) return -1 ;
  byte_copy(ip6, 16, sa.sin6_addr.s6_addr) ;
  uint16_unpack_big((char *)&sa.sin6_port, port) ;
  return r ;
}

#else

#include <errno.h>
#include "uint16.h"

int socket_recv6 (int s, char *buf, unsigned int len, char *ip6, uint16 *port)
{
  (void)s ;
  (void)buf ;
  (void)len ;
  (void)ip6 ;
  (void)port ;
  return (errno = ENOSYS, -1) ;
}

#endif
