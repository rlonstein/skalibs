/* ISC license. */

/* MT-unsafe */

#include <unistd.h>
#include "uint32.h"
#include "bytestr.h"
#include "tai.h"
#include "surf.h"
#include "random-internal.h"
#include "random.h"

void dns_random_init (char const *data) /* 128 chars */
{
  char tmp[160] ;
  struct taia t ;
  byte_copy(tmp, 128, data) ;
  taia_now(&t) ;
  taia_pack(tmp + 128, &t) ;
  uint32_pack(tmp + 144, getpid()) ;
  uint32_pack(tmp + 148, getppid()) ;
 /* more space in tmp+152 and tmp+156 if needed */
  surf_sinit(&surf_here, tmp) ;
}
