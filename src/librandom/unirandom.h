/* ISC license. */

#ifndef UNIRANDOM_H
#define UNIRANDOM_H

#include "surf.h"

struct randomfd
{
  int fd ;
  unsigned int nb : 1 ;
} ;

#define RANDOMFD_ZERO { -1, 0 }

union unirandominfo
{
  SURFSchedule surf_ctx ;
  struct randomfd file ;
} ;

#define UNIRANDOMINFO_ZERO { SURFSCHEDULE_ZERO }

typedef struct unirandom unirandom, *unirandom_ref, **unirandom_ref_ref ;
struct unirandom
{
  unsigned int (*readb) (union unirandominfo *, char *, unsigned int) ;
  unsigned int (*readnb) (union unirandominfo *, char *, unsigned int) ;
  int (*init) (union unirandominfo *) ;
  int (*finish) (union unirandominfo *) ;
  union unirandominfo data ;
  unsigned int initted : 1 ;
} ;

#define UNIRANDOM_ZERO { 0, 0, 0, 0, UNIRANDOMINFO_ZERO, 0 }

extern int unirandom_register_devrandom (unirandom_ref) ;
extern int unirandom_register_devurandom (unirandom_ref) ;
extern int unirandom_register_hasegd (unirandom_ref) ;
extern int unirandom_register_surf (unirandom_ref) ;

extern int unirandom_init (unirandom_ref) ;
extern unsigned int unirandom_readb (unirandom_ref, char *, unsigned int) ;
extern unsigned int unirandom_readnb (unirandom_ref, char *, unsigned int) ;
extern int unirandom_finish (unirandom_ref) ;


#endif
