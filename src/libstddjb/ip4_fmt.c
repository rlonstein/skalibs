/* ISC license. */

#include "fmtscan.h"

unsigned int ip4_fmt(char *s, char const *ip)
{
  unsigned int len = 0 ;
  unsigned int i, j ;
  for (j = 0 ; j < 4 ; j++)
  {
    i = fmt_ulong(s, (unsigned long)(unsigned char) ip[j]) ;
    len += i ;
    if (s) s += i ;
    if (j == 3) break ;
    if (s) *s++ = '.' ;
    ++len ;
  }
  return len;
}
