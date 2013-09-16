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

int ttymodes_getw (int fd, ttymodes_ref t)
{
  register int r ;
  do
    r = ioctl(fd, TIOCGWINSZ, &t->ws) ;
  while ((r == -1) && (errno == EINTR)) ;
  return r ;
}
