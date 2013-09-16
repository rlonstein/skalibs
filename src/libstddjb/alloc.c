/* ISC license. */

#include <errno.h>
#include <stdlib.h>
#include "sysdeps.h"

#include "alloc.h"
#include "alloc_0.h"

#ifdef DEBUG_ALLOC
# include "uint32.h"
# include "fmtscan.h"
# include "strerr2.h"

# define PLM1(x) strerr_warn3x(PROG, ": debug_alloc: ", (x))
# define PLM2(x, y) strerr_warn4x(PROG, ": debug_alloc: ", (x), (y))
# define PLM3(x, y, z) strerr_warn5x(PROG, ": debug_alloc: ", (x), (y), (z))
# define PLM4(x, y, z, t) strerr_warn6x(PROG, ": debug_alloc: ", (x), (y), (z), (t))
# define PLM5(a, b, c, d, e) strerr_warn7x(PROG, ": debug_alloc: ", (a), (b), (c), (d), (e))
# define PLM6(a, b, c, d, e, f) strerr_warn8x(PROG, ": debug_alloc: ", (a), (b), (c), (d), (e), (f))
# define PLM7(a, b, c, d, e, f, g) strerr_warn9x(PROG, ": debug_alloc: ", (a), (b), (c), (d), (e), (f), (g))
# define PLM(x) PLM1(x)
#endif

aligned_char_ref alloc (unsigned int n)
{
#ifdef HASMALLOC0
  register aligned_char_ref p = (aligned_char_ref)malloc(n) ;
#else
  register aligned_char_ref p = n ? (aligned_char_ref)malloc(n) : (aligned_char_ref)alloc_0 ;
#endif
#ifdef DEBUG_ALLOC
  {
    char fmtp[2 + UINT32_XFMT] = "0x" ;
    char fmt[UINT_FMT] ;
    fmtp[2+uint32_xfmt(fmtp+2, (uint32)p)] = 0 ;
    fmt[uint_fmt(fmt, n)] = 0 ;
    PLM4("alloc(", fmt, ") -> ", fmtp) ;
  }
#endif
  return p ;
}

void alloc_free (void *p)
{
  register int e = errno ;
#ifdef DEBUG_ALLOC
  {
    char fmtp[2 + UINT32_XFMT] = "0x" ;
    fmtp[2+uint32_xfmt(fmtp+2, (uint32)p)] = 0 ;
    PLM3("alloc_free(", fmtp, ")") ;
  }
#endif
#ifndef HASMALLOC0
  if ((char *)p == alloc_0) return ;
#endif
  free(p) ;
  errno = e ;
}

int alloc_realloc (aligned_char_ref *x, unsigned int n)
{
#ifdef HASMALLOC0
  aligned_char_ref y = n ? (aligned_char_ref)realloc(*x, n) : (free(*x), (aligned_char_ref)malloc(0)) ;
#else
  aligned_char_ref y = (*x == alloc_0) ? alloc(n) : n ? (aligned_char_ref)realloc(*x, n) : (free(*x), alloc_0) ;
#endif
#ifdef DEBUG_ALLOC
  {
    char fmtx[2 + UINT32_XFMT] = "0x" ;
    char fmty[2 + UINT32_XFMT] = "0x" ;
    char fmt[UINT_FMT] ;
    fmtx[2+uint32_xfmt(fmtx+2, (uint32)(*x))] = 0 ;
    fmty[2+uint32_xfmt(fmty+2, (uint32)y)] = 0 ;
    fmt[uint_fmt(fmt, n)] = 0 ;
    PLM6("alloc_realloc(&", fmtx, ", ", fmt, ") -> new address = ", fmty) ;
  }
#endif
  if (!y) return 0 ;
  *x = y ;
  return 1 ;
}

int alloc_re (aligned_char_ref *x, unsigned int dummy, unsigned int n)
{
#ifdef DEBUG_ALLOC
  {
    char fmtx[2 + UINT32_XFMT] = "0x" ;
    char fmtold[UINT_FMT] ;
    char fmtnew[UINT_FMT] ;
    fmtx[2+uint32_xfmt(fmtx+2, (uint32)(*x))] = 0 ;
    fmtold[uint_fmt(fmtold, dummy)] = 0 ;
    fmtnew[uint_fmt(fmtnew, n)] = 0 ;
    PLM7("alloc_re(&", fmtx, ", ", fmtold, ", ", fmtnew, ") -> see next alloc_realloc()") ;
  }
#endif
  (void)dummy ;
  return alloc_realloc(x, n) ;
}
