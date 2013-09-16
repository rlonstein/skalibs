/* ISC license. */

#include <errno.h>
#include "uint64.h"
#include "fmtscan.h"

unsigned int uint640_scan_upto_base (char const *s, uint64 *u, uint64 n, unsigned char base)
{
  register unsigned int pos = uint64_scan_upto_base(s, u, n, base) ;
  if (!pos) return (errno = EINVAL, 0) ;
  if (!s[pos]) return pos ;
  errno = (fmtscan_num(s[pos], base) < base) ? EDOM : EINVAL ;
  return 0 ;
}
