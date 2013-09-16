/* ISC license. */

#include <unistd.h>
#include "sysdeps.h"
#ifdef HASSTREAMS
#include <stropts.h>
#endif
#include <sys/ioctl.h>
#include <termios.h>
#include "ttymodes.h"

int ttymodes_remote (int fd, ttymodes_ref t)
{
#ifdef HASTIOCREMOTE
  {
    int on = 1 ;
    if (ioctl(fd, TIOCREMOTE, &on) == -1) return -1 ;
  }
#else
  (void)fd ;
#endif
  ttymodes_raw(t) ;
  return 0 ;
}
