/* ISC license. */

#include <termios.h>
#include "ttymodes.h"

void ttymodes_echo_off (ttymodes_ref t)
{
  t->ti.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL) ;
}
