/* ISC license. */

#include "uint64.h"
#include "fmtscan.h"

unsigned int uint64_scan_upto_base (char const *s, uint64 *u, uint64 n, unsigned char base)
{
  uint64 result = 0 ;
  unsigned int pos = 0 ;

  for (;; pos++)
  {
    register unsigned char c = fmtscan_num(s[pos], base) ;
    if ((c >= base) || (result > ((n - c) / base))) break ;
    result = result * base + c ;
  }
  if (pos) *u = result ;
  return pos ;
}
