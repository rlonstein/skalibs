/* ISC license. */

#ifndef FMTSCAN_INTERNAL_H
#define FMTSCAN_INTERNAL_H

#include "uint64.h"

#define SCANU(abbr, type, n) \
unsigned int abbr##_scan_base (char const *s, type *u, unsigned char base) \
{ \
  uint64 result ; \
  register unsigned int pos = uint64_scan_upto_base(s, &result, n, base) ; \
  if (pos) *u = (type)result ; \
  return pos ; \
} \

#define SCANU0(abbr, type, n) \
unsigned int abbr##0_scan_base (register char const *s, register type *u, unsigned char base) \
{ \
  uint64 result ; \
  register unsigned int pos = uint640_scan_upto_base(s, &result, n, base) ; \
  if (pos) *u = (type)result ; \
  return pos ; \
} \

#define SCANS(type, cstname) \
unsigned int type##_scan (char const *s, type *n) \
{ \
  unsigned type tmp ; \
  register unsigned int r = 0 ; \
  register unsigned int sign = 0 ; \
  if (*s == '-') \
  { \
    r = 1 + u##type##_scan(s+1, &tmp) ; \
    if (r == 1) return 0 ; \
    if (tmp == 0) *n = 0 ; \
    else \
    { \
      if (tmp-1 > -(cstname##_MIN+1)) \
      { \
        tmp /= 10 ; \
        r-- ; \
      } \
      *n = cstname##_MIN + (-(cstname##_MIN+1) - (tmp-1)) ; \
    } \
    return r ; \
  } \
  if (*s == '+') (s++, sign++) ; \
  r = u##type##_scan(s, &tmp) ; \
  if (!r) return 0 ; \
  r += sign ; \
  if (tmp > cstname##_MAX) \
  { \
    tmp /= 10 ; \
    r-- ; \
  } \
  *n = tmp ; \
  return r ; \
} \
                                                                                                          

#endif
