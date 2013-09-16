/* ISC license. */

#ifndef IP46_H
#define IP46_H

#include "sysdeps.h"
#include "skalibs-config.h"

#if defined(HASIPV6) && defined(SKALIBS_FLAG_WANTIPV6)

#include "uint32.h"
#include "fmtscan.h"
#include "tai.h"
#include "socket.h"

#define IP6_ANY   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define IP6_LOCAL "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\001"

typedef struct ip46_s ip46_t, *ip46_t_ref ;
struct ip46_s
{
  char ip[16] ;
  unsigned int is6 : 1 ;
} ;
#define IP46_ZERO { .ip = IP6_ANY, .is6 = 0 }

#define ip46_is6(i) ((i)->is6)
#define ip46_get(i, h) ((i)->ip)
#define ip46_fmt(s, i) ((i)->is6 ? ip6_fmt(s, (i)->ip) : ip4_fmt(s, (i)->ip))
extern unsigned int ip46_scan (char const *s, ip46_t_ref) ;
#define socket_connect46(s, i, port) ((i)->is6 ? socket_connect6(s, (i)->ip, port) : socket_connect4(s, (i)->ip, port))

#else

typedef char ip46_t[4], *ip46_t_ref[4] ;

#define ip46_is6(ip) 0
#define ip46_get(ip, h) (ip)
#define ip46_fmt(s, i) ip4_fmt(s, i)
#define ip46_scan(s, i) ip4_scan(s, i)
#define socket_connect46(s, i, port) socket_connect4(s, i, port)

#endif

extern int socket_deadlineconnstamp46 (int, ip46_t const *, uint16, struct taia const *, struct taia *) ;
#define socket_deadlineconnstamp46_g(fd, ip, port, deadline) socket_deadlineconnstamp46(fd, ip, port, (deadline), &STAMP)

#endif
