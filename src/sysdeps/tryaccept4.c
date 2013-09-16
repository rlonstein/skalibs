#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main (void)
{
  struct sockaddr blah ;
  socklen_t blahlen = sizeof(blah) ;
  int fd = open("/dev/null", O_RDONLY | O_NDELAY) ;
  if (fd < 0) return 111 ;
  if ((accept4(fd, &blah, &blahlen, SOCK_NONBLOCK) < 0) && (errno != ENOTSOCK)) return 1 ;
  return 0 ;
}
