/* ISC license. */

/*
 * The original libancillary license is a 3-clause ("Revised") BSD license.
 * This copy of libancillary is under the ISC license, with permission
 * of the original author (Nicolas George).
 * Any modifications are mine (Laurent Bercot).
 */

/***************************************************************************
 * libancillary - black magic on Unix domain sockets
 * (C) Nicolas George
 * ancillary.h - public header
 ***************************************************************************/

#ifndef ANCILLARY_H__
#define ANCILLARY_H__

/***************************************************************************
 * Start of the readable part.
 ***************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>

#define ANCIL_MAX_N_FDS 960
/*
 * Maximum number of fds that can be sent or received using the "easy"
 * functions; this is so that all can fit in one page.
 */

extern int ancil_send_fds_with_buffer (int, int const *, unsigned int, void *) ;
/*
 * ancil_send_fds_with_buffer(sock, n_fds, fds, buffer)
 *
 * Sends the file descriptors in the array pointed by fds, of length n_fds
 * on the socket sock.
 * buffer is a writeable memory area large enough to hold the required data
 * structures.
 * Returns: -1 and errno in case of error, 0 in case of success.
 */

extern int ancil_recv_fds_with_buffer (int, int *, unsigned int, void *) ;
/*
 * ancil_recv_fds_with_buffer(sock, n_fds, fds, buffer)
 *
 * Receives *n_fds file descriptors into the array pointed by fds
 * from the socket sock.
 * buffer is a writeable memory area large enough to hold the required data
 * structures.
 * Returns: -1 and errno in case of error, the actual number of received fd
 * in case of success
 */

#define ANCIL_FD_BUFFER(n) struct { struct cmsghdr h ; int fd[n] ; }
/* ANCIL_FD_BUFFER(n)
 *
 * A structure type suitable to be used as buffer for n file descriptors.
 * Example:
 * ANCIL_FD_BUFFER(42) buffer;
 * ancil_recv_fds_with_buffer(sock, 42, my_fds, &buffer);
 */

extern int ancil_send_fds (int, int const *, unsigned int) ;
/*
 * ancil_send_fds(sock, n_fds, fds)
 *
 * Sends the file descriptors in the array pointed by fds, of length n_fds
 * on the socket sock.
 * n_fds must not be greater than ANCIL_MAX_N_FDS.
 * Returns: -1 and errno in case of error, 0 in case of success.
 */

extern int ancil_recv_fds (int, int *, unsigned int) ;
/*
 * ancil_recv_fds(sock, n_fds, fds)
 *
 * Receives *n_fds file descriptors into the array pointed by fds
 * from the socket sock.
 * *n_fds must not be greater than ANCIL_MAX_N_FDS.
 * Returns: -1 and errno in case of error, the actual number of received fds
 * in case of success.
 */


extern int ancil_send_fd (int, int) ;
/* ancil_recv_fd(sock, fd);
 *
 * Sends the file descriptor fd on the socket sock.
 * Returns : -1 and errno in case of error, 0 in case of success.
 */

extern int ancil_recv_fd (int, int *) ;
/* ancil_send_fd(sock, &fd);
 *
 * Receives the file descriptor fd from the socket sock.
 * Returns : -1 and errno in case of error, 0 in case of success.
 */

#endif /* ANCILLARY_H__ */
