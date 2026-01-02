#define _GNU_SOURCE /* for ppoll */
#include <poll.h>
#include <stdlib.h>
#include "../../config.h"
#if defined(VGO_netbsd)
#include <sys/timespec.h>
#endif

int main()
{
   int uninit;
   struct pollfd fds[] = {{-1, uninit, 0}, {2, POLLIN, 0}};

   poll(fds, 2, 100);

#if defined(HAVE_PPOLL)
   struct timespec timeout = {0, 1e8};
   ppoll(fds, 2, &timeout, NULL);
#endif
}
