/* Public domain. */

#define _GNU_SOURCE /* KMA, glibc maintainers */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/un.h>

int main (void)
{
  int s ;
  struct ucred dummy ;
  int len = sizeof(struct ucred) ;
  return getsockopt(s, SOL_SOCKET, SO_PEERCRED, &dummy, &len) ;
}
