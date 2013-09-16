/* ISC license. */

#ifndef ALLOC_H
#define ALLOC_H

#include "gccattributes.h"

typedef char aligned_char gccattr_aligned ;
typedef aligned_char *aligned_char_ref, **aligned_char_ref_ref ;

extern aligned_char_ref alloc (unsigned int) gccattr_malloc ;
extern void alloc_free (void *) ;
extern int alloc_re (aligned_char_ref_ref, unsigned int, unsigned int) ;
extern int alloc_realloc (aligned_char_ref_ref, unsigned int) ;

#endif
