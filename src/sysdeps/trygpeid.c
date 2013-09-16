#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>

int main (void)
{
  int uid ;
  int gid ;
  int s = 0 ;

  return getpeereid(s, &uid, &gid) ;
}
