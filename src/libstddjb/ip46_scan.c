/* ISC license. */

#include "sysdeps.h"
#include "skalibs-config.h"

#if defined(HASIPV6) && defined(SKALIBS_FLAG_WANTIPV6)

#include "fmtscan.h"
#include "ip46.h"

unsigned int ip46_scan (char const *s, ip46_t_ref ip)
{
  unsigned int len = ip6_scan(s, ip->ip) ;
  if (len) ip->is6 = 1 ;
  else
  {
    len = ip4_scan(s, ip->ip) ;
    if (len) ip->is6 = 0 ;
  }
  return len ;
}

#endif
