#define _GNU_SOURCE
#include <fcntl.h>

int main (void)
{
  int fd = openat(0, "/", O_RDONLY) ;
  return (fd < 0) ;
}
