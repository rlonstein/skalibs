/* ISC license. */

#ifndef FMTSCAN_H
#define FMTSCAN_H

#include "gccattributes.h"
#include "uint32.h"
#include "uint64.h"



 /* fmt */


extern unsigned char fmtscan_asc (unsigned char) gccattr_const ;

extern unsigned int str_fmt (char *, char const *) ;
extern unsigned int strn_fmt (char *, char const *, unsigned int) ;

#define IP4_FMT 20
extern unsigned int ip4_fmt (char *, char const *) ;
extern unsigned int ip4_fmtu32 (char *, uint32) ;

extern unsigned int ucharn_fmt (char *, char const *, unsigned int) ;
extern unsigned int ucharn_fmt_little (char *, char const *, unsigned int) ;

#define IP6_FMT 40
extern unsigned int ip6_fmt (char *, char const *) ;

#define USHORT_FMT UINT64_FMT
#define USHORT_OFMT UINT64_OFMT
#define USHORT_XFMT UINT64_XFMT
#define USHORT_BFMT UINT64_BFMT
#define UINT_FMT UINT64_FMT
#define UINT_OFMT UINT64_OFMT
#define UINT_XFMT UINT64_XFMT
#define UINT_BFMT UINT64_BFMT
#define ULONG_FMT UINT64_FMT
#define ULONG_OFMT UINT64_OFMT
#define ULONG_XFMT UINT64_XFMT
#define ULONG_BFMT UINT64_BFMT

#define short_fmt(s, u) long_fmt((s), (long)(short)(u))
#define int_fmt(s, u) long_fmt((s), (long)(int)(u))
extern unsigned int long_fmt (char *, long) ;

#define ushort_fmt_base(s, u, b) uint64_fmt_base((s), (uint64)(unsigned short)(u), (b))
#define ushort0_fmt_base(s, u, n, b) uint640_fmt_base((s), (uint64)(unsigned short)(u), (n), (b))
#define ushort_fmt(s, u) ushort_fmt_base((s), (u), 10)
#define ushort0_fmt(s, u, n) ushort0_fmt_base((s), (u), (n), 10)
#define ushort_ofmt(s, u) ushort_fmt_base((s), (u), 8)
#define ushort0_ofmt(s, u, n) ushort0_fmt_base((s), (u), (n), 8)
#define ushort_xfmt(s, u) ushort_fmt_base((s), (u), 16)
#define ushort0_xfmt(s, u, n) ushort0_fmt_base((s), (u), (n), 16)
#define ushort_bfmt(s, u) ushort_fmt_base((s), (u), 2)
#define ushort0_bfmt(s, u, n) ushort0_fmt_base((s), (u), (n), 2)

#define uint_fmt_base(s, u, b) uint64_fmt_base((s), (uint64)(unsigned int)(u), (b))
#define uint0_fmt_base(s, u, n, b) uint640_fmt_base((s), (uint64)(unsigned int)(u), (n), (b))
#define uint_fmt(s, u) uint_fmt_base((s), (u), 10)
#define uint0_fmt(s, u, n) uint0_fmt_base((s), (u), (n), 10)
#define uint_ofmt(s, u) uint_fmt_base((s), (u), 8)
#define uint0_ofmt(s, u, n) uint0_fmt_base((s), (u), (n), 8)
#define uint_xfmt(s, u) uint_fmt_base((s), (u), 16)
#define uint0_xfmt(s, u, n) uint0_fmt_base((s), (u), (n), 16)
#define uint_bfmt(s, u) uint_fmt_base((s), (u), 2)
#define uint0_bfmt(s, u, n) uint0_fmt_base((s), (u), (n), 2)

#define ulong_fmt_base(s, u, b) uint64_fmt_base((s), (uint64)(unsigned long)(u), (b))
#define ulong0_fmt_base(s, u, n, b) uint640_fmt_base((s), (uint64)(unsigned long)(u), (n), (b))
#define ulong_fmt(s, u) ulong_fmt_base((s), (u), 10)
#define ulong0_fmt(s, u, n) ulong0_fmt_base((s), (u), (n), 10)
#define ulong_ofmt(s, u) ulong_fmt_base((s), (u), 8)
#define ulong0_ofmt(s, u, n) ulong0_fmt_base((s), (u), (n), 8)
#define ulong_xfmt(s, u) ulong_fmt_base((s), (u), 16)
#define ulong0_xfmt(s, u, n) ulong0_fmt_base((s), (u), (n), 16)
#define ulong_bfmt(s, u) ulong_fmt_base((s), (u), 2)
#define ulong0_bfmt(s, u, n) ulong0_fmt_base((s), (u), (n), 2)


 /* Old compatibility. Please upgrade ! */

#define FMT_ULONG ULONG_FMT
#define FMT_LEN ((char *) 0)

#define fmt_str str_fmt
#define fmt_strn strn_fmt
#define fmt_ucharn ucharn_fmt

#define fmt_short(s, u) long_fmt((s), (long)(short)(u))
#define fmt_int(s, u) long_fmt((s), (long)(int)(u))
#define fmt_long(s, u) long_fmt((s), (u))

#define fmt_ushort(s, u) ushort_fmt_base((s), (u), 10)
#define oshort_fmt(s, u) ushort_fmt_base((s), (u), 8)
#define fmt_oshort(s, u) ushort_fmt_base((s), (u), 8)
#define xshort_fmt(s, u) ushort_fmt_base((s), (u), 16)
#define fmt_xshort(s, u) ushort_fmt_base((s), (u), 16)
#define fmt_uint(s, u) uint_fmt_base((s), (u), 10)
#define oint_fmt(s, u) uint_fmt_base((s), (u), 8)
#define fmt_oint(s, u) uint_fmt_base((s), (u), 8)
#define xint_fmt(s, u) uint_fmt_base((s), (u), 16)
#define fmt_xint(s, u) uint_fmt_base((s), (u), 16)
#define fmt_ulong(s, u) ulong_fmt_base((s), (u), 10)
#define olong_fmt(s, u) ulong_fmt_base((s), (u), 8)
#define fmt_olong(s, u) ulong_fmt_base((s), (u), 8)
#define xlong_fmt(s, u) ulong_fmt_base((s), (u), 16)
#define fmt_xlong(s, u) ulong_fmt_base((s), (u), 16)



 /* scan */


extern unsigned char fmtscan_num (unsigned char, unsigned char) gccattr_const ;

extern unsigned int ip4_scan (char const *, char *) ;
extern unsigned int ip4_scanu32 (char const *, uint32 *) ;
extern unsigned int ip4_scanlist (uint32 *, unsigned int, char const *, unsigned int *) ;
extern unsigned int ip6_scan (char const *, char *) ;
extern unsigned int ip6_scanlist (char *, unsigned int, char const *, unsigned int *) ;

extern unsigned int ucharn_scan (char const *, char *, unsigned int) ;
extern unsigned int ucharn_scan_little (char const *, char *, unsigned int) ;
extern unsigned int ucharn_findlen (char const *) gccattr_pure ;

extern unsigned int short_scan (char const *, short *) ;
extern unsigned int int_scan (char const *, int *) ;
extern unsigned int long_scan (char const *, long *) ;

extern unsigned int ushort_scan_base (char const *, unsigned short *, unsigned char) ;
extern unsigned int ushort0_scan_base (char const *, unsigned short *, unsigned char) ;
#define ushort_scan(s, u) ushort_scan_base((s), (u), 10)
#define ushort0_scan(s, u) ushort0_scan_base((s), (u), 10)
#define ushort_oscan(s, u) ushort_scan_base((s), (u), 8)
#define ushort0_oscan(s, u) ushort0_scan_base((s), (u), 8)
#define ushort_xscan(s, u) ushort_scan_base((s), (u), 16)
#define ushort0_xscan(s, u) ushort0_scan_base((s), (u), 16)
#define ushort_bscan(s, u) ushort_scan_base((s), (u), 2)
#define ushort0_bscan(s, u) ushort0_scan_base((s), (u), 2)

extern unsigned int uint_scan_base (char const *, unsigned int *, unsigned char) ;
extern unsigned int uint0_scan_base (char const *, unsigned int *, unsigned char) ;
#define uint_scan(s, u) uint_scan_base((s), (u), 10)
#define uint0_scan(s, u) uint0_scan_base((s), (u), 10)
#define uint_oscan(s, u) uint_scan_base((s), (u), 8)
#define uint0_oscan(s, u) uint0_scan_base((s), (u), 8)
#define uint_xscan(s, u) uint_scan_base((s), (u), 16)
#define uint0_xscan(s, u) uint0_scan_base((s), (u), 16)
#define uint_bscan(s, u) uint_scan_base((s), (u), 2)
#define uint0_bscan(s, u) uint0_scan_base((s), (u), 2)

extern unsigned int ulong_scan_base (char const *, unsigned long *, unsigned char) ;
extern unsigned int ulong0_scan_base (char const *, unsigned long *, unsigned char) ;
#define ulong_scan(s, u) ulong_scan_base((s), (u), 10)
#define ulong0_scan(s, u) ulong0_scan_base((s), (u), 10)
#define ulong_oscan(s, u) ulong_scan_base((s), (u), 8)
#define ulong0_oscan(s, u) ulong0_scan_base((s), (u), 8)
#define ulong_xscan(s, u) ulong_scan_base((s), (u), 16)
#define ulong0_xscan(s, u) ulong0_scan_base((s), (u), 16)
#define ulong_bscan(s, u) ulong_scan_base((s), (u), 2)
#define ulong0_bscan(s, u) ulong0_scan_base((s), (u), 2)


 /* Old compatibility. Please upgrade ! */

#define scan_ucharn ucharn_scan
#define scan_short short_scan
#define scan_int int_scan
#define scan_long long_scan

#define scan_ushort(s, u) ushort_scan((s), (u))
#define scan_ushort0(s, u) ushort0_scan((s), (u))
#define oshort_scan(s, o) ushort_oscan((s), (o))
#define scan_oshort(s, o) ushort_oscan((s), (o))
#define xshort_scan(s, x) ushort_xscan((s), (x))
#define scan_xshort(s, x) ushort_xscan((s), (x))
#define scan_uint(s, u) uint_scan((s), (u))
#define scan_uint0(s, u) uint0_scan((s), (u))
#define oint_scan(s, o) uint_oscan((s), (o))
#define scan_oint(s, o) uint_oscan((s), (o))
#define xint_scan(s, x) uint_xscan((s), (x))
#define scan_xint(s, x) uint_xscan((s), (x))
#define scan_ulong(s, u) ulong_scan((s), (u))
#define scan_ulong0(s, u) ulong0_scan((s), (u))
#define olong_scan(s, o) ulong_oscan((s), (o))
#define scan_olong(s, o) ulong_oscan((s), (o))
#define xlong_scan(s, x) ulong_xscan((s), (x))
#define scan_xlong(s, x) ulong_xscan((s), (x))
#define scan_8long(s, o) ulong_oscan((s), (o))

#endif
