#pragma once

#include <unistd.h>
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
  static int Connect(const char *host, uint16_t port) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
      return -1;
    }
    struct sockaddr_in saddr;
    inet_pton(AF_INET, host, &saddr.sin_addr.s_addr);
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    int ret = connect(sock_fd, (struct sockaddr *)&saddr, sizeof(saddr));
    if (ret < 0) {
      close(sock_fd);
      return -1;
    }
    return sock_fd;
  }
};

}  // namespace sock