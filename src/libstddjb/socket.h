/* ISC license. */

#ifndef SOCKET_H
#define SOCKET_H

#include "gccattributes.h"
#include "uint16.h"
#include "uint32.h"
#include "tai.h"
#include "djbunix.h"

 /* INET and INET6 domain socket operations */

#define socket_tcp() socket_tcp_nb()
#define socket_tcp_b() socket_tcp_internal(0)
#define socket_tcp_nb() socket_tcp_internal(DJBUNIX_FLAG_NB)
#define socket_tcp_coe() socket_tcp_internal(DJBUNIX_FLAG_COE)
#define socket_tcp_nbcoe() socket_tcp_internal(DJBUNIX_FLAG_NB|DJBUNIX_FLAG_COE)
extern int socket_tcp_internal (unsigned int) ;

#define socket_tcp6() socket_tcp6_nb()
#define socket_tcp6_b() socket_tcp6_internal(0)
#define socket_tcp6_nb() socket_tcp6_internal(DJBUNIX_FLAG_NB)
#define socket_tcp6_coe() socket_tcp6_internal(DJBUNIX_FLAG_COE)
#define socket_tcp6_nbcoe() socket_tcp6_internal(DJBUNIX_FLAG_NB|DJBUNIX_FLAG_COE)
extern int socket_tcp6_internal (unsigned int) ;

#define socket_udp() socket_udp_nb()
#define socket_udp_b() socket_udp_internal(0)
#define socket_udp_nb() socket_udp_internal(DJBUNIX_FLAG_NB)
#define socket_udp_coe() socket_udp_internal(DJBUNIX_FLAG_COE)
#define socket_udp_nbcoe() socket_udp_internal(DJBUNIX_FLAG_NB|DJBUNIX_FLAG_COE)
extern int socket_udp_internal (unsigned int) ;

#define socket_udp6() socket_udp6_nb()
#define socket_udp6_b() socket_udp6_internal(0)
#define socket_udp6_nb() socket_udp6_internal(DJBUNIX_FLAG_NB)
#define socket_udp6_coe() socket_udp6_internal(DJBUNIX_FLAG_COE)
#define socket_udp6_nbcoe() socket_udp6_internal(DJBUNIX_FLAG_NB|DJBUNIX_FLAG_COE)
extern int socket_udp6_internal (unsigned int) ;

extern int socket_waitconn (int, struct taia const *, struct taia *) ;
#define socket_waitconn_g(fd, deadline) socket_waitconn(fd, (deadline), &STAMP)
extern int socket_deadlineconn (int, char const *, uint16, struct taia const *) gccattr_deprecated ;
extern int socket_deadlineconnstamp4 (int, char const *, uint16, struct taia const *, struct taia *) ;
#define socket_deadlineconnstamp(s, ip, port, deadline, stamp) socket_deadlineconnstamp4(s, ip, port, deadline, stamp)
#define socket_deadlineconnstamp4_g(fd, ip, port, deadline) socket_deadlineconnstamp4(fd, ip, port, (deadline), &STAMP)
extern int socket_deadlineconnstamp4_u32 (int, uint32, uint16, struct taia const *, struct taia *) ;
#define socket_deadlineconnstamp4_u32_g(fd, ip, port, deadline) socket_deadlineconnstamp4_u32(fd, ip, port, (deadline), &STAMP)

extern int socket_timeoutconn (int, char const *, uint16, unsigned int) ;
extern int socket_connect4 (int, char const *, uint16) ;
extern int socket_connect4_u32 (int, uint32, uint16) ;
extern int socket_connected (int) gccattr_const ;
extern int socket_bind4 (int, char const *, uint16) ;
extern int socket_bind4_reuse (int, char const *, uint16) ;
extern int socket_listen (int, int) ;

extern int socket_connect6 (int, char const *, uint16) ;
extern int socket_deadlineconnstamp6 (int, char const *, uint16, struct taia const *, struct taia *) ;
#define socket_deadlineconnstamp6_g(fd, ip6, port, deadline) socket_deadlineconnstamp6(fd, ip6, port, (deadline), &STAMP)
extern int socket_bind6 (int, char const *, uint16) ;
extern int socket_bind6_reuse (int, char const *, uint16) ;

#define socket_accept4(s, ip, port) socket_accept4_internal(s, ip, (port), 0)
#define socket_accept4_nb(s, ip, port) socket_accept4_internal(s, ip, (port), DJBUNIX_FLAG_NB)
#define socket_accept4_coe(s, ip, port) socket_accept4_internal(s, ip, (port), DJBUNIX_FLAG_COE)
#define socket_accept4_nbcoe(s, ip, port) socket_accept4_internal(s, ip, (port), DJBUNIX_FLAG_NB|DJBUNIX_FLAG_COE)
extern int socket_accept4_internal (int, char *, uint16 *, unsigned int) ;
extern int socket_recv4 (int, char *, unsigned int, char *, uint16 *) ;
extern int socket_send4 (int, char const *, unsigned int, char const *, uint16) ;
extern int socket_local4 (int, char *, uint16 *) ;
extern int socket_remote4 (int, char *, uint16 *) ;

#define socket_accept6(s, ip6, port) socket_accept6_internal(s, ip6, (port), 0)
#define socket_accept6_nb(s, ip6, port) socket_accept6_internal(s, ip6, (port), DJBUNIX_FLAG_NB)
#define socket_accept6_coe(s, ip6, port) socket_accept6_internal(s, ip6, (port), DJBUNIX_FLAG_COE)
#define socket_accept6_nbcoe(s, ip6, port) socket_accept6_internal(s, ip6, (port), DJBUNIX_FLAG_NB|DJBUNIX_FLAG_COE)
extern int socket_accept6_internal (int, char *, uint16 *, unsigned int) ;
extern int socket_recv6 (int, char *, unsigned int, char *, uint16 *) ;
extern int socket_send6 (int, char const *, unsigned int, char const *, uint16) ;
extern int socket_local6 (int, char *, uint16 *) ;
extern int socket_remote6 (int, char *, uint16 *) ;

extern int socket_ipoptionskill (int) ;
extern int socket_tcpnodelay (int) ;
extern void socket_tryreservein (int, unsigned int) ;


 /* Timed send and recv operations (for dgram sockets) */

extern int socket_sendnb4 (int, char const *, unsigned int, char const *, uint16, struct taia const *, struct taia *) ;
#define socket_sendnb4_g(fd, msg, msglen, ip, port, deadline) socket_sendnb4(fd, msg, msglen, ip, port, (deadline), &STAMP)
extern int socket_sendnb4_u32 (int, char const *, unsigned int, uint32, uint16, struct taia const *, struct taia *) ;
#define socket_sendnb4_u32_g(fd, msg, msglen, ip, port, deadline) socket_sendnb4_u32(fd, msg, msglen, ip, port, (deadline), &STAMP)
extern int socket_recvnb4 (int, char *, unsigned int, char *, uint16 *, struct taia const *, struct taia *) ;
#define socket_recvnb4_g(fd, buf, buflen, ip, port, deadline) socket_recvnb4(fd, buf, buflen, ip, port, (deadline), &STAMP)
extern int socket_recvnb4_u32 (int, char *, unsigned int, uint32 *, uint16 *, struct taia const *, struct taia *) ;
#define socket_recvnb4_u32_g(fd, buf, buflen, ip, port, deadline) socket_recvnb4_u32(fd, buf, buflen, ip, port, (deadline), &STAMP)

extern int socket_sendnb6 (int, char const *, unsigned int, char const *, uint16, struct taia const *, struct taia *) ;
#define socket_sendnb6_g(fd, msg, msglen, ip6, port, deadline) socket_sendnb6(fd, msg, msglen, ip6, port, (deadline), &STAMP)
extern int socket_recvnb6 (int, char *, unsigned int, char *, uint16 *, struct taia const *, struct taia *) ;
#define socket_recvnb6_g(fd, buf, buflen, ip6, port, deadline) socket_recvnb6(fd, buf, buflen, ip6, port, (deadline), &STAMP)

#endif
