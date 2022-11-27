#pragma once

#include <netdb.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/tcp.h>


namespace sock {

class SocketUtils {
 public:
  static int Connect() { return -1; }
};

}  // namespace sock