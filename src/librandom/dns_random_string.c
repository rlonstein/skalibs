/* ISC license. */

/* MT-unsafe */

#include "surf.h"
#include "random-internal.h"
#include "random.h"

void dns_random_string (char *s, unsigned int n)
{
  surf(&surf_here, s, n) ;
}
