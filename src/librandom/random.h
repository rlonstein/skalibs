/* ISC license. */

/* MT-unsafe functions only. Use rrandom for MT-safety. */

#ifndef RANDOM_H
#define RANDOM_H

#include "gccattributes.h"
#include "stralloc.h"

extern int badrandom_init (void) ;
extern unsigned char badrandom_char (void) ;
extern unsigned int badrandom_int (unsigned int) ;
extern unsigned int badrandom_string (char *, unsigned int) ;
extern void badrandom_finish (void) ;

extern int goodrandom_init (void) ;
extern unsigned char goodrandom_char (void) ;
extern unsigned int goodrandom_int (unsigned int) ;
extern unsigned int goodrandom_string (char *, unsigned int) ;
extern void goodrandom_finish (void) ;

extern void dns_random_init (char const *) gccattr_deprecated ; /* 128 chars */
extern void dns_random_string (char *, unsigned int) gccattr_deprecated ;
extern unsigned int dns_random (unsigned int) gccattr_deprecated ;

#define random_init badrandom_init
#define random_char badrandom_char
#define random_int badrandom_int
#define random_string badrandom_string
#define random_finish badrandom_finish

extern int random_name (char *, unsigned int) ;
extern int random_sauniquename (stralloc *, unsigned int) ;
extern int random_unsort (char *, unsigned int, unsigned int) ;

#endif
