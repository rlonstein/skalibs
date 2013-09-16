/* ISC license. */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "djbunix.h"
#include "pflocal.h"
#include "webipc.h"

int ipc_stream_internal (unsigned int flags)
{
  return socket_internal(PF_LOCAL, SOCK_STREAM, 0, flags) ;
}
