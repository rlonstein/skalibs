/* ISC license. */

#ifndef GENSETDYN_H
#define GENSETDYN_H

#include "stralloc.h"
#include "functypes.h"

typedef struct gensetdyn_s gensetdyn, *gensetdyn_ref ;
struct gensetdyn_s
{
  stralloc storage ;
  stralloc bits ;
  unsigned int esize ;
  unsigned int base ;
  unsigned int fracnum ;
  unsigned int fracden ;
} ;

#define GENSETDYN_ZERO { STRALLOC_ZERO, STRALLOC_ZERO, 1, 0, 0, 1 }
extern gensetdyn const gensetdyn_zero ;

#define GENSETDYN_INIT(type, base, fracnum, fracden) { STRALLOC_ZERO, STRALLOC_ZERO, sizeof(type), base, fracnum, fracden }
extern void gensetdyn_init (gensetdyn_ref, unsigned int, unsigned int, unsigned int, unsigned int) ;

#define gensetdyn_size(g) ((g)->bits.len)
extern int gensetdyn_ready (gensetdyn_ref, unsigned int) ;
#define gensetdyn_readyplus(x, n) gensetdyn_ready(x, gensetdyn_size(x) + (n))
extern void gensetdyn_free (gensetdyn_ref) ;

extern int gensetdyn_new (gensetdyn_ref, unsigned int *) ;
extern int gensetdyn_delete (gensetdyn_ref, unsigned int) ;

extern char *gensetdyn_p (gensetdyn const *, unsigned int) ;
#define GENSETDYN_P(type, g, i) ((type *)gensetdyn_p(g, i))

extern unsigned int gensetdyn_iter (gensetdyn_ref, iterfunc_t_ref, void *) ;

#endif
