/* ISC license. */

#ifndef GENSET_H
#define GENSET_H

#include "bitarray.h"
#include "functypes.h"

typedef struct genset_s genset, *genset_ref ;
struct genset_s
{
  char *storage ;
  unsigned char *bits ;
  unsigned int esize ;
  unsigned int max ;
  unsigned int n ;
} ;

#define GENSET_ZERO { 0, 0, 1, 0, 0 }
extern void genset_init (genset_ref, void *, unsigned char *, unsigned int, unsigned int) ;
#define GENSET_init(g, type, storage, bits, size) genset_init(g, storage, bits, sizeof(type), size)

#define genset_p(type, g, i) ((type *)((g)->storage + (i) * (g)->esize))
extern unsigned int genset_new (genset_ref) ;
extern int genset_delete (genset_ref, unsigned int) ;
extern unsigned int genset_iter (genset_ref, iterfunc_t_ref, void *) ;


#define GENSETB_TYPE(type, size) struct { type storage[size] ; unsigned char bits[bitarray_div8(size)] ; genset info ; }
#define GENSETB_init(g, type, size) GENSET_init(&(g)->info, type, (g)->storage, (g)->bits, size)
#define gensetb_p(type, g, i) genset_p(type, &(g)->info, i)
#define gensetb_new(g) genset_new(&(g)->info)
#define gensetb_delete(g, i) genset_delete(&(g)->info, i)
#define gensetb_iter(g, f, p) genset_iter(&(g)->info, f, p)

#endif
