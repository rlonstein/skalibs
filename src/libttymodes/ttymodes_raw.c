/* ISC license. */

#include <sys/ioctl.h>
#include <termios.h>
#include "ttymodes.h"

void ttymodes_raw (ttymodes_ref t)
{
  t->ti.c_iflag &= ~(BRKINT | IGNBRK | IGNPAR | PARMRK) ;
  t->ti.c_iflag &= ~(ISTRIP | IXON | IXOFF | ICRNL | INLCR | IGNCR | IMAXBEL) ;
  t->ti.c_oflag &= ~OPOST ;
  t->ti.c_lflag &= ~(ECHO | ECHONL) ;
  t->ti.c_lflag &= ~(ICANON | ISIG | IEXTEN) ;
  t->ti.c_cflag &= ~(CSIZE | PARENB) ;
  t->ti.c_cflag |= CS8 ;
  t->ti.c_cc[VMIN] = 1 ;
  t->ti.c_cc[VTIME] = 0 ;
}
