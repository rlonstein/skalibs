/* ISC license. */

#include <unistd.h>
#include "sysdeps.h"
#ifdef HASSTREAMS
#include <stropts.h>
#endif
#include <termios.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "ttymodes.h"

int ttymodes_setw (int fd, ttymodes const *t)
{
  register int r ;
  do
    r = ioctl(fd, TIOCSWINSZ, &t->ws) ;
  while ((r == -1) && (errno == EINTR)) ;
  return r ;
}
