/* ISC license. */

#ifndef TTYMODES_H
#define TTYMODES_H

#include <sys/ioctl.h>
#include <termios.h>

#define TERMIOS_PACK (36+8*NCCS)
#define WINSIZE_PACK 8
#define TTYMODES_PACK (TERMIOS_PACK+WINSIZE_PACK)

typedef struct ttymodes ttymodes, *ttymodes_ref ;
struct ttymodes
{
  struct winsize ws ;
  struct termios ti ;
} ;

extern void ttymodes_packw (char *, ttymodes const *) ;
extern void ttymodes_packt (char *, ttymodes const *) ;
extern void ttymodes_pack (char *, ttymodes const *) ;
extern void ttymodes_unpackw (char const *, ttymodes_ref) ;
extern unsigned int ttymodes_unpackt (char const *, ttymodes_ref) ;
extern unsigned int ttymodes_unpack (char const *, ttymodes_ref) ;

extern int ttymodes_gett (int, ttymodes_ref) ;
extern int ttymodes_getw (int, ttymodes_ref) ;
extern int ttymodes_get (int, ttymodes_ref) ;
extern int ttymodes_sett (int, ttymodes const *) ;
extern int ttymodes_sett_nohang (int, ttymodes const *) ;
extern int ttymodes_setw (int, ttymodes const *) ;
extern int ttymodes_set (int, ttymodes const *) ;
extern int ttymodes_set_nohang (int, ttymodes const *) ;

extern void ttymodes_raw (ttymodes_ref) ;
extern void ttymodes_sane (ttymodes_ref) ;
extern int ttymodes_remote (int, ttymodes_ref) ;
extern void ttymodes_echo_off (ttymodes_ref) ;
extern void ttymodes_echo_on (ttymodes_ref) ;

#endif
