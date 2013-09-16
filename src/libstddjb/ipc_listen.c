/* ISC license. */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "webipc.h"

int ipc_listen (int s, int backlog)
{
  return listen(s, backlog) ;
}
