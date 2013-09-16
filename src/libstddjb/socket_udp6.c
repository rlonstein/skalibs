/* ISC license. */

#include "sysdeps.h"
#include "skalibs-config.h"

#if defined(HASIPV6) && defined(SKALIBS_FLAG_WANTIPV6)

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include "djbunix.h"
#include "socket.h"

int socket_udp6_internal (unsigned int flags)
{
  int fd = socket_internal(AF_INET6, SOCK_DGRAM, 0, flags) ;
  if (fd < 0) return fd ;
  {
    int option = 1 ;
    if (setsockopt(fd, IPPROTO_IPV6, IPV6_V6ONLY, &option, sizeof(option)) < 0)
    {
      register int e = errno ;
      fd_close(fd) ;
      errno = e ;
      return -1 ;
    }
  }
  return fd ;
}

#else

#include <errno.h>
#include "socket.h"

int socket_udp6_internal (unsigned int flags)
{
  (void)flags ;
  return (errno = ENOSYS, -1) ;
}

#endif
