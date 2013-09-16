/* ISC license. */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include "bytestr.h"
#include "error.h"
#include "pflocal.h"
#include "webipc.h"

int ipc_send (int fd, char const *s, unsigned int len, char const *path)
{
  struct sockaddr_un sa ;
  register unsigned int l = str_len(path) ;
  if (l > IPCPATH_MAX) return (errno = EPROTO, -1) ;
  byte_zero((char *)&sa, sizeof sa) ;
  sa.sun_family = PF_LOCAL ;
  byte_copy(sa.sun_path, l+1, path) ;
  return sendto(fd, s, len, 0, (struct sockaddr *)&sa, sizeof sa) ;
}
