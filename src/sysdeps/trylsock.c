#include <sys/types.h>
#include <sys/socket.h>

int main (void)
{
  shutdown(0, 0) ;
  return 0 ;
}
