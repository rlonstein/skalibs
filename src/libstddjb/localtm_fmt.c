/* ISC license. */

#include "fmtscan.h"
#include "djbtime.h"

unsigned int localtm_fmt (char *s, struct tm const *l)
{
  char *p = s ;
  p += ulong_fmt(p, 1900 + l->tm_year) ; *p++ = '-' ;
  ulong0_fmt(p, 1 + l->tm_mon, 2) ; p += 2 ; *p++ = '-' ;
  ulong0_fmt(p, l->tm_mday, 2) ; p += 2 ; *p++ = ' ' ;
  ulong0_fmt(p, l->tm_hour, 2) ; p += 2 ; *p++ = ':' ;
  ulong0_fmt(p, l->tm_min, 2) ; p += 2 ; *p++ = ':' ;
  ulong0_fmt(p, l->tm_sec, 2) ; p += 2 ;
  return p - s ;
}
