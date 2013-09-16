/* ISC license. */

#include "sysdeps.h"

#ifdef HASGETPEEREID
/* syscall exists - do nothing */

#else

#include "getpeereid.h"

#ifdef HASSO_PEERCRED
/* implementation with SO_PEERCRED */

 /* Seriously, glibc maintainers, ever heard of ascendant compatibility? */
#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/un.h>

int getpeereid (int s, int *u, int *g)
{
  struct ucred blah ;
  unsigned int len = sizeof(blah) ;

  if (getsockopt(s, SOL_SOCKET, SO_PEERCRED, &blah, &len) == -1)
    return -1 ;
  *u = blah.uid ;
  *g = blah.gid ;
  return 0 ;
}

#else
/* nonexistent getpeereid : stub implementation */

#include <errno.h>

int getpeereid (int s, int *uid, int *gid)
{
  (void)s ;
  *uid = *gid = -1 ;
  errno = ENOSYS ;
  return -1 ;
}

#endif
#endif
