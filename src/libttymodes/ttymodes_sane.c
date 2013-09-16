/* ISC license. */

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include "bytestr.h"
#include "ttymodes.h"

void ttymodes_sane (ttymodes_ref t)
{
  unsigned int i ;
  byte_zero((char *)t, sizeof(ttymodes)) ;
  for (i = 0; i < sizeof(t->ti.c_cc) / sizeof(*t->ti.c_cc) ; i++)
    t->ti.c_cc[i] = _POSIX_VDISABLE ;

  t->ti.c_iflag = BRKINT | IGNBRK | ICRNL | IXON | IMAXBEL ;
  t->ti.c_oflag = OPOST | ONLCR ;
  t->ti.c_lflag = ISIG | ICANON | IEXTEN | ECHO | ECHOE | ECHOKE | ECHOCTL ;
  t->ti.c_cflag = CS8 | CREAD | HUPCL ;

  cfsetispeed(&t->ti, B38400) ;
  cfsetospeed(&t->ti, B38400) ;

  t->ti.c_cc[VMIN] = 1 ;
  t->ti.c_cc[VTIME] = 0 ;
  t->ti.c_cc[VINTR] = 3 ;
  t->ti.c_cc[VQUIT] = 28 ;
  t->ti.c_cc[VERASE] = 127 ;
  t->ti.c_cc[VKILL] = 21 ;
  t->ti.c_cc[VEOF] = 4 ;
  t->ti.c_cc[VSTART] = 17 ;
  t->ti.c_cc[VSTOP] = 19 ;
#ifdef VSUSP
  t->ti.c_cc[VSUSP] = 26 ;
#endif
#ifdef VDSUSP
  t->ti.c_cc[VDSUSP] = 25 ;
#endif
#ifdef VREPRINT
  t->ti.c_cc[VREPRINT] = 18 ;
#endif
#ifdef VDISCARD
  t->ti.c_cc[VDISCARD] = 15 ;
#endif
#ifdef VWERASE
  t->ti.c_cc[VWERASE] = 23 ;
#endif
#ifdef VLNEXT
  t->ti.c_cc[VLNEXT] = 22 ;
#endif
#ifdef VSTATUS
  t->ti.c_cc[VSTATUS] = 20 ;
#endif
}
